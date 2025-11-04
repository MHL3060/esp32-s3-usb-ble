#include <stdint.h>
#include <FreeRTOS.h>
#include <semphr.h>


class AtomicCounter {
    private:
        uint32_t counter = 0;
        SemaphoreHandle_t counter_mutex;

        public:
           AtomicCounter();
           uint32_t add(uint32_t value);
           void reset();
           uint32_t get();
           uint32_t setAndGet(uint32_t value);
           
};