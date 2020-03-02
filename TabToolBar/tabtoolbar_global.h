#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(TABTOOLBAR_LIB)
#  define TABTOOLBAR_EXPORT Q_DECL_EXPORT
# else
#  define TABTOOLBAR_EXPORT Q_DECL_IMPORT
# endif
#else
# define TABTOOLBAR_EXPORT
#endif
