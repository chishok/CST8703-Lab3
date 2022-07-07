#ifndef AC_FEASIBILITY_H
#define AC_FEASIBILITY_H

#include <stdbool.h>

/**
 * @brief Scheduling task timing
 *
 */
typedef struct AcTask
{
    /**
     * @brief Worst-case computation time \f[ C \f]
     *
     * This can also be referred to as worst-case execution time (WCET)
     */
    double comp_time;
    /**
     * @brief Required period of task execution \f[ T \f].
     *
     * This can also be considered the periodic deadline for the task.
     */
    double period;
} AcTask;

/**
 * @brief Check if task set size is greater than 0 and is rate monotonic (increasing period)
 *
 * @param task_list List of tasks in rate-monotonic task set
 * @param num_tasks Number of tasks in task set
 * @return true if inputs are valid rate monotonic
 * @return false if input is invalid
 */
bool ac_feasibility_validate_rm(const AcTask *task_list, const size_t num_tasks);

/**
 * @brief Compute utilization factor.
 *
 * @param task_list List of tasks in rate-monotonic task set
 * @param num_tasks Number of tasks in task set
 * @return Processor utilization factor
 */
double ac_feasibility_utilization_factor(const AcTask *task_list, const size_t num_tasks);

/**
 * @brief Compute least upper bound for rate monotonic scheduling.
 *
 * @param num_tasks Number of tasks in task set
 * @return Least upper bound processor utilization factor
 */
double ac_feasibility_rm_least_upper_bound(const size_t num_tasks);

/**
 * @brief Determine feasibility based on hyperbolic criteria for rate monotonic scheduling.
 *
 * @param task_list List of tasks in rate-monotonic task set
 * @param num_tasks Number of tasks in task set
 * @return true if feasible
 * @return false if feasibility is unkown
 */
bool ac_feasibility_rm_hyperbolic(const AcTask *task_list, const size_t num_tasks);

/**
 * @brief Determine feasibility based on response time analysis for deadline monotonic scheduling.
 *
 * @param task_list List of tasks in rate-monotonic task set
 * @param num_tasks Number of tasks in task set
 * @return true if feasible
 * @return false if not feasible
 */
bool ac_feasibility_dm_response_time(const AcTask *task_list, const size_t num_tasks);

/**
 * @brief Calculate and print feasibility analysis for list of tasks.
 *
 * @param name Name of task set
 * @param task_list List of tasks in rate-monotonic task set
 * @param num_tasks Number of tasks in task set
 */
void ac_feasibility_analysis(const char *name, const AcTask *task_list, const size_t num_tasks);

#endif
