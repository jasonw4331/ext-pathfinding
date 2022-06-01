#ifndef PHP_PATHFINDING_H
# define PHP_PATHFINDING_H

extern zend_module_entry pathfinding_module_entry;
# define phpext_pathfinding_ptr &pathfinding_module_entry

# define PHP_PATHFINDING_VERSION "0.1.1"

#ifdef ZTS
#include "TSRM.h"
#endif

# if defined(ZTS) && defined(COMPILE_DL_PATHFINDING)
ZEND_TSRMLS_CACHE_EXTERN()
# endif

#endif	/* PHP_PATHFINDING_H */