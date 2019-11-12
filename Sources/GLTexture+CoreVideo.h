//
//  GLTexture+CoreVideo.h
//  CeedGL
//
//  Created by Raphael Sebbe on 30/07/14.
//  Copyright (c) 2014 Creaceed. All rights reserved.
//

#import <CeedGL/GLTexture.h>
#import <CoreVideo/CoreVideo.h>

typedef NS_ENUM(NSInteger, GLVideoPlane) {
	GLVideoPlaneDefault,	// for non-planar buffers
	GLVideoPlaneLuma,		// plane 0
	GLVideoPlaneChroma		// plane 1
};

#if TARGET_OS_IPHONE
#define CeedGLTextureCacheRef CVOpenGLESTextureCacheRef
#define CeedGLTextureRef CVOpenGLESTextureRef

#else
 #define CeedGLTextureCacheRef CVOpenGLTextureCacheRef
 #define CeedGLTextureRef CVOpenGLTextureRef
#endif


@interface GLTexture (CoreVideo)

+ (GLTexture*)textureFromPixelBuffer:(CVPixelBufferRef)pixelBuffer inTextureCache:(CeedGLTextureCacheRef)textureCache plane:(GLVideoPlane)plane;

@end
