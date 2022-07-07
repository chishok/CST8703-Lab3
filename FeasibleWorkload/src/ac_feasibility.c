#define _POSIX_C_SOURCE 200809L
#include <unistd.h>

#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <errno.h>

#include "ac_feasibility.h"

bool ac_feasibility_validate_rm(const AcTask *task_list, const size_t num_tasks)
{
    const double tolerance = 1.0e-9;
    double last_period = tolerance;
    if (num_tasks == 0)
    {
        return false;
    }
    else
    {
        for (size_t idx = 0; idx < num_tasks; ++idx)
        {
            if (task_list[idx].period < last_period || task_list[idx].comp_time < 0.0)
            {
                return false;
            }
            last_period = task_list[idx].period;
        }
    }
    return true;
}

double ac_feasibility_utilization_factor(const AcTask *task_list, const size_t num_tasks)
{
    /*
     * STUDENT WORK SECTION BEGIN
     * ==========================
     */

    // This routine is meant to calculate the utilization factor, but it is not correctly implemented.
    // Refer to the background section in the lab for the equation.

    // Hint: The equations use the symbol U to denote utilization factor
    //       Read the description of type AcTask in the header file

    double u = 0.0;
    for (size_t idx = 0; idx < num_tasks; ++idx)
    {
        u += task_list[idx].comp_time;
    }
    return u;

    /*
     * ========================
     * STUDENT WORK SECTION END
     */
}

double ac_feasibility_rm_least_upper_bound(const size_t num_tasks)
{
    /*
     * STUDENT WORK SECTION BEGIN
     * ==========================
     */

    // This routine is meant to calculate the least upper bound utilization factor, but it is not correctly implemented.
    // Refer to the background section in the lab for the equation.

    // Hint: The equation symbol is Ulub.
    //       Use the standard math function `pow` to fix the equation

    const double n = (double)num_tasks;
    return n * (2.0 * (1.0 / n) - 1.0);

    /*
     * ========================
     * STUDENT WORK SECTION END
     */
}

bool ac_feasibility_rm_hyperbolic(const AcTask *task_list, const size_t num_tasks)
{
    /*
     * STUDENT WORK SECTION BEGIN
     * ==========================
     */

    // This routine is meant to test the hyperbolic feasibility condition.
    // Refer to the background section in the lab for the equation.

    double prod_u = (1.0 + task_list[0].comp_time / task_list[0].period);
    for (size_t idx = 1; idx < num_tasks; ++idx)
    {
        prod_u *= (1.0 + task_list[idx].comp_time);
    }
    return (prod_u <= 2.0);

    /*
     * ========================
     * STUDENT WORK SECTION END
     */
}

bool ac_feasibility_dm_response_time(const AcTask *task_list, const size_t num_tasks)
{
    for (size_t i = 0; i < num_tasks; ++i)
    {
        // initial interference
        double interference = 0.0;
        for (size_t k = 0; k < i; ++k)
        {
            interference += task_list[k].comp_time;
        }
        // iterate response time and interference
        bool done = false;
        while (!done)
        {
            /*
            * STUDENT WORK SECTION BEGIN
            * ==========================
            */

            // Implement the logic for the do-while loop in the lab description
            // "Figure 1: Response time analysis algorithm"

            done = true;

            /*
            * ========================
            * STUDENT WORK SECTION END
            */
        }
    }
    return true;
}

void ac_feasibility_analysis(const char *name, const AcTask *task_list, const size_t num_tasks)
{
    if (!ac_feasibility_validate_rm(task_list, num_tasks))
    {
        errno = EINVAL;
        perror("Failed to process utilization factor for set of tasks. Check input periods and computation times are greater than 0.");
    }
    else
    {
        const double u = ac_feasibility_utilization_factor(task_list, num_tasks);
        const double u_lub = ac_feasibility_rm_least_upper_bound(num_tasks);
        const bool feasible_rm_hyperbolic = ac_feasibility_rm_hyperbolic(task_list, num_tasks);
        const bool feasible_dm_response_time = ac_feasibility_dm_response_time(task_list, num_tasks);

        printf("\n%s:\n", name);
        for (size_t idx = 0; idx < num_tasks; ++idx)
        {
            printf("  %zu:(C=%g,T=%g)", idx, task_list[idx].comp_time, task_list[idx].period);
        }
        printf("\n");
        printf("  Utilization factor U = %.4f\n", u);
        printf("  Least upper bound U_lub = %.4f\n", u_lub);
        printf("  Feasible (U less than 1.0): %s\n", (u <= 1.0 ? "Maybe" : "No"));
        printf("  Feasible (RM LUB): %s\n", (u < u_lub ? "Yes" : (u <= 1.0 ? "Maybe" : "No")));
        printf("  Feasible (RM hyperbolic): %s\n", (feasible_rm_hyperbolic ? "Yes" : (u <= 1.0 ? "Maybe" : "No")));
        printf("  Feasible (DM response time): %s\n", (feasible_dm_response_time ? "Yes" : "No"));
    }
}
