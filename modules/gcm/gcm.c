#include "../../sr_module.h"

MODULE_VERSION

static char* secret = NULL;
static param_export_t params[]={
  {"secret", STR_PARAM, &secret }
};

static int m_gcm_notify(struct sip_msg *msg, char * token)
{
  LM_INFO("Notifying GCM. Token:%s Secret:%s\n", token, secret);
  return 1;
}

static cmd_export_t cmds[]={
  {"gcm_notify",    (cmd_function)m_gcm_notify, 1, 0, 0, ANY_ROUTE},
  {0, 0, 0, 0, 0, 0}
};

struct module_exports exports = {
  "gcm",           /* module name */
  DEFAULT_DLFLAGS, /* dlopen flags */
  cmds,            /* exported functions */
  params,          /* exported parameters */
  0,               /* exported statistics */
  0,               /* exported MI functions */
  0,               /* exported pseudo-variables */
  0,               /* extra processes */
  0,               /* module initialization function */
  0,               /* response function*/
  0,               /* destroy function */
  0                /* per-child init function */
};
