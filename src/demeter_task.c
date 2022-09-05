// ATOS PROJECT, 2022
// DEMETER
// File description:
// Wow, such plugin, much data!
//___________________________________________________________________________________________________________________________________________

#include "src/common/log.h"
#include "src/slurmd/common/task_plugin.h"
#include "demeter_task.h"

const char plugin_name[]        = "task demeter plugin";
const char plugin_type[]        = "task/demeter :";
const uint32_t plugin_version   = SLURM_VERSION_NUMBER;
char *plugin_data_path = NULL;

extern int init (void)
{
    plugin_data_path = get_conf_path();
    if (plugin_data_path == NULL) {
        return SLURM_ERROR;
    }
	debug("%s loaded", plugin_name);
	return SLURM_SUCCESS;
}

extern int fini (void)
{
    return SLURM_SUCCESS;
}

extern int task_p_post_term (stepd_step_rec_t *job, stepd_step_task_info_t *task)
{
    
	return SLURM_SUCCESS;
}

// UNUSED
//___________________________________________________________________________________________________________________________________________

extern int task_p_slurmd_batch_request (batch_job_launch_msg_t *req)
{
	return SLURM_SUCCESS;
}

extern int task_p_slurmd_launch_request (launch_tasks_request_msg_t *req, uint32_t node_id)
{
	return SLURM_SUCCESS;
}

extern int task_p_slurmd_suspend_job (uint32_t job_id)
{
	return SLURM_SUCCESS;
}

extern int task_p_slurmd_resume_job (uint32_t job_id)
{
	return SLURM_SUCCESS;
}

extern int task_p_pre_setuid (stepd_step_rec_t *job)
{
	return SLURM_SUCCESS;
}

extern int task_p_pre_launch (stepd_step_rec_t *job)
{
	return SLURM_SUCCESS;
}

extern int task_p_pre_set_affinity(stepd_step_rec_t *job, uint32_t node_tid)
{
	return SLURM_SUCCESS;
}

extern int task_p_set_affinity(stepd_step_rec_t *job, uint32_t node_tid)
{
	return SLURM_SUCCESS;
}

extern int task_p_post_set_affinity(stepd_step_rec_t *job, uint32_t node_tid)
{
	return SLURM_SUCCESS;
}

extern int task_p_post_step (stepd_step_rec_t *job)
{
	return SLURM_SUCCESS;
}

extern int task_p_add_pid (pid_t pid)
{
	return SLURM_SUCCESS;
}
