// ATOS PROJECT, 2022
// DEMETER
// File description:
// Wow, such plugin, much data!
//___________________________________________________________________________________________________________________________________________

#include <stdlib.h>
#include "src/common/parse_config.h"
#include "src/common/xmalloc.h"
#include "demeter_task.h"

char *get_conf_path(void)
{
    s_p_options_t options[] = {
    {"PluginDataPath", S_P_STRING},
    {NULL}};
    s_p_hashtbl_t *tbl = NULL;
    char *tmp_plugin_data_path = NULL;
    char *plugin_data_path = NULL;
    char conf_path[] = "/etc/slurm/demeter.conf";

    tbl = s_p_hashtbl_create(options);
    if (s_p_parse_file(tbl, NULL, conf_path, false) == SLURM_ERROR) {
        s_p_hashtbl_destroy(tbl);
        return strdup("/var/log/demeter_data");
    }
    s_p_get_string(&tmp_plugin_data_path, "PluginDataPath", tbl);
    s_p_hashtbl_destroy(tbl);
    if (tmp_plugin_data_path != NULL && is_writable_path(tmp_plugin_data_path)) {
        plugin_data_path = strdup(tmp_plugin_data_path);
        xfree(tmp_plugin_data_path);
        return (plugin_data_path);
    }
    if (tmp_plugin_data_path != NULL)
        xfree(tmp_plugin_data_path);
    return strdup("/var/log/demeter_data");
}
