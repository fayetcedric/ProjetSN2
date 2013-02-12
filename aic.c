#include "aic.h"

void fct_init_AIC()
{
  AIC_SMR6=AIC_PRIOR|
           AIC_SRCTYPE_INT_EDGE_TRIGGER;
           
  AIC_SVR6=(int)fct_irq_IncremCptTimer0;
  AIC_IECR=(1<<TC0_ID);
}
