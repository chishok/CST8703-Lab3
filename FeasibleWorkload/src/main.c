#define _POSIX_C_SOURCE 200809L
#include <unistd.h>
#include <stdlib.h>

/**
 * @brief This macro determine an array by looking at the memory
 *        size of the entire array (in bytes) divided by the
 *        memory of a single element of the array.
 */
#define ARRAY_SIZE(x) (sizeof(x) / sizeof(x[0]))

#include "ac_feasibility.h"

int main(void)
{
    // This task set has three tasks. The `period` T (same as deadline) must be monotonically
    // increasing for each task so that the rate-monotonic feasibility tests can
    // be applied. The `comp_time` C or worst-case execution time (wcet) is also
    // set for each task and should be less than the period.
    AcTask ex0_tasks[] = {
        { .comp_time=1, .period=2 },
        { .comp_time=1, .period=10 },
        { .comp_time=2, .period=15 }
    };
    // The size is determined with a macro so that AcTask ex0_tasks[] does not need an explicit size
    // argument in the square brackets. This makes the code less error prone since the task set can be
    // any length and there's no need to manually count the size of the array.
    const size_t ex0_num_tasks = ARRAY_SIZE(ex0_tasks);

    AcTask ex1_tasks[] = {
        { .comp_time=3, .period=5 },
        { .comp_time=1, .period=8 },
        { .comp_time=1, .period=10 }
    };
    const size_t ex1_num_tasks = ARRAY_SIZE(ex1_tasks);

    /*
     * STUDENT WORK SECTION BEGIN
     * ==========================
     */

    // Create the task sets from the lab description

    // AcTask ex2_tasks[] = {};
    // const size_t ex2_num_tasks = ARRAY_SIZE(ex2_tasks);

    // AcTask ex3_tasks[] = {};
    // const size_t ex3_num_tasks = ARRAY_SIZE(ex3_tasks);

    // AcTask ex4_tasks[] = {};
    // const size_t ex4_num_tasks = ARRAY_SIZE(ex4_tasks);

    // AcTask ex5_tasks[] = {};
    // const size_t ex5_num_tasks = ARRAY_SIZE(ex5_tasks);

    ac_feasibility_analysis("ex0", ex0_tasks, ex0_num_tasks);
    ac_feasibility_analysis("ex1", ex1_tasks, ex1_num_tasks);
    // ac_feasibility_analysis("ex2", ex2_tasks, ex2_num_tasks);
    // ac_feasibility_analysis("ex3", ex3_tasks, ex3_num_tasks);
    // ac_feasibility_analysis("ex4", ex4_tasks, ex4_num_tasks);
    // ac_feasibility_analysis("ex5", ex5_tasks, ex5_num_tasks);

    /*
     * STUDENT WORK SECTION END
     * ==========================
     */

    return EXIT_SUCCESS;
}
