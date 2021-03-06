/*
 * Copyright (C) 2013 Freie Universität Berlin
 *
 * This file subject to the terms and conditions of the GNU Lesser General
 * Public License. See the file LICENSE in the top level directory for more
 * details.
 */

/**
 * @addtogroup  core_internal
 * @{
 *
 * @file        kernel_internal.h
 * @brief       prototypes for kernel internal functions
 *
 * @author      INRIA
 * @author      Oliver Hahm <oliver.hahm@inria.fr>
 */

#ifndef KERNEL_INTERNAL_H_
#define KERNEL_INTERNAL_H_

/**
 * @brief   Initializes scheduler and creates main and idle task
 */
void kernel_init(void);

/**
 * @brief   Optionally: initializes platform specifics (devices, pin configuration etc.)
 */
void board_init(void);

/**
 * @brief   Gets called upon thread creation to set CPU registers
 *
 * @param[in] task_func     First function to call within the thread
 * @param[in] stack_start   Start address of the stack
 * @param[in] stack_size    Stack size
 *
 * @return stack pointer
 */
char *thread_stack_init(void  (*task_func)(void), void *stack_start, int stack_size);

/**
 * @brief  Removes thread from scheduler and set status to #STATUS_STOPPED
 */
void sched_task_exit(void);

/**
 * @brief   Prints human readable, ps-like thread information for debugging purposes
 */
void thread_print_stack(void);

/**
 * @brief       Reboot the system
 *
 * @param mode  The argument is ignored and only used for conformity
 *              with existing reboot implementations for now.
 *
 * @return      This call never returns when successful. -1 is returned otherwise.
 */
int reboot_arch(int mode);

/** @} */
#endif /* KERNEL_INTERNAL_H_ */
