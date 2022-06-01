#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

extern "C" {
#include "php.h"
#include "ext/standard/info.h"
#include "php_pathfinding.h"
}

/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(pathfinding)
{
#if defined(ZTS) && defined(COMPILE_DL_PATHFINDING)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif

	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(pathfinding)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "pathfinding support", "enabled");
	php_info_print_table_end();
}
/* }}} */

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_function_name, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, x, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, y, IS_LONG, 0)
ZEND_END_ARG_INFO()

PHP_FUNCTION(function_name) {
	zend_long x;

	ZEND_PARSE_PARAMETERS_START_EX(ZEND_PARSE_PARAMS_THROW, 1, 1)
		Z_PARAM_LONG(x)
	ZEND_PARSE_PARAMETERS_END();

	RETURN_NULL();
}

static const zend_function_entry pathfinding_functions[] = {
	PHP_FE(function_name, arginfo_function_name)
	PHP_FE_END
};

/* {{{ pathfinding_module_entry
 */
zend_module_entry pathfinding_module_entry = {
	STANDARD_MODULE_HEADER,
	"pathfinding",
	pathfinding_functions,
	NULL, /* MINIT */
	NULL, /* MSHUTDOWN */
	NULL, /* RINIT */
	NULL, /* PHP_RSHUTDOWN */
	PHP_MINFO(pathfinding),
	PHP_PATHFINDING_VERSION,
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_PATHFINDING
extern "C" {
# ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
# endif
ZEND_GET_MODULE(pathfinding)
}
#endif