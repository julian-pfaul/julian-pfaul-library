#pragma once

#include <julian-pfaul/runtime.h>

#include <system_error>

namespace julian_pfaul::runtime {

    inline bool start() {
        if(s_thread.joinable()) {
            return false;
        }

        s_event_queue = std::queue<event>();
        s_thread      = std::thread(entry);
        return true;
    }

    inline bool stop(const size attempts_to_try) {
        for(size shutdown_attempts = attempts_to_try; shutdown_attempts > 0; --shutdown_attempts) {
            if(s_thread.joinable()) {
                fire_event(event::shutdown_event);

                try {
                    s_thread.join();
                    return true;
                } catch(const std::system_error& e) {
                    // TODO: implement logging
                }
            }
        }

        return false;
    }

    inline void fire_event(const event event) {
        s_event_queue.push(event);
    }

    inline bool is_running() {
        return s_thread.joinable();
    }

    inline void entry() {
        while(is_running()) {
            if(not s_event_queue.empty()) {
                switch(s_event_queue.front()) {
                    case event::shutdown_event:
                        goto shutdown;
                    default: break;
                }

                s_event_queue.pop();
            }
        }

shutdown:
        return;
    }

}