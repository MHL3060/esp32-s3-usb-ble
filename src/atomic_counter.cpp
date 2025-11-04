#include <stdint.h>
#include <Arduino.h>
#include "atomic_counter.h"

AtomicCounter::AtomicCounter() {
    counter_mutex = xSemaphoreCreateMutex();
    counter =0;
}


void AtomicCounter::reset() {
    xSemaphoreTake( counter_mutex, portMAX_DELAY );
    counter =0;
    xSemaphoreGive(counter_mutex);
}

uint32_t AtomicCounter::add(uint32_t value) {
    xSemaphoreTake( counter_mutex, portMAX_DELAY );
    counter = counter + value;
    xSemaphoreGive(counter_mutex);
    return counter;
}

uint32_t AtomicCounter::get() {
    uint32_t cpyValue = counter;
    return cpyValue;
}

uint32_t AtomicCounter::setAndGet(uint32_t value) {
    xSemaphoreTake( counter_mutex, portMAX_DELAY );
    counter = value;
    xSemaphoreGive(counter_mutex);
    return counter;
}