#pragma once

#include <lstate.h>

namespace runtime {
    void leave( );
    bool start( std::uintptr_t job );
}