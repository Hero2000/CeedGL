//
//  GLDebug.h
//  CeedGL
//
//  Created by Raphael Sebbe on 01/11/10.
//  Copyright (c) 2010 Creaceed. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CeedGL/GLPlatform.h>

GL_EXTERN void ceedgl_debug_terminate(void);

#ifdef DEBUG
#define GL_ASSERT(condition)\
{\
if(!(condition)) \
{ \
NSString *s = [NSString stringWithFormat:@"File: %s, Line: %d \nCondition: (%s)\n\n",\
__FILE__, __LINE__, #condition];\
NSLog(@"Debugging... %@",s);\
ceedgl_debug_terminate();\
exit(1); \
}\
}
#define GLDebugRequire GL_ASSERT
#ifdef GL_DISABLE_LOG
#define GLLog(...)
#define GLLogMethod(...)
#define GLLogMethodArg(...)
#else
#define GLLog(...) { NSLog(@"    %@", [NSString stringWithFormat:__VA_ARGS__]); }
#define GLLogMethod() { NSLog(@"> %@", NSStringFromSelector(_cmd)); }
#define GLLogMethodArg(...) { NSLog(@"M %@, %@", NSStringFromSelector(_cmd), [NSString stringWithFormat:__VA_ARGS__]); }
#endif
#else
#define GL_ASSERT(condition)
#define GLDebugRequire GL_ASSERT
#define GLLog(...)
#define GLLogMethod(...)
#define GLLogMethodArg(...)
#endif

#define GLLogWarning NSLog

#define GLCheckError() GLCheckErrorImpl(__FILE__, __LINE__)

static inline void GLCheckErrorImpl(const char *file, int line) {
	GLenum err;
	if((err = glGetError()) != GL_NO_ERROR) {
		// Set breakpoint here to debug.
		GLLogWarning(@"GL error: 0x%x (%s:%d)", err, file, line);
	}
}

// raises an exception if condition is true
#define GL_EXCEPT(condition, exception) {if((condition)) [NSException raise:exception format:@""];}
#define GL_EXCEPT_NOTIMPLEMENTED() GL_EXCEPT(1, @"Not implemented")
