#ifndef DEMOLIB_GLOBAL_H
#define DEMOLIB_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(DEMOLIB_LIBRARY)
#define DEMOLIB_EXPORT Q_DECL_EXPORT
#else
#define DEMOLIB_EXPORT Q_DECL_IMPORT
#endif

#endif // DEMOLIB_GLOBAL_H
