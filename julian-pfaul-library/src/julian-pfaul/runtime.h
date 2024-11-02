#pragma once

#include <queue>
#include <thread>

#include <julian-pfaul/definitions.h>
#include <julian-pfaul/runtime/event.h>

namespace julian_pfaul::runtime {
    inline auto s_thread      = std::thread();
    inline auto s_event_queue = std::queue<event>();

    inline bool start();
    inline bool stop(size attempts_to_try = 5);

    inline void fire_event(event event);

    inline bool is_running();

    inline void entry();

}

#include <julian-pfaul/runtime/runtime.inl>
