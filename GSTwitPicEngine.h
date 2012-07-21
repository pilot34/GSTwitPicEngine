//
//  GSTwitPicEngine.h
//  TwitPic Uploader
//
//  Created by Gurpartap Singh on 19/06/10.
//  Copyright 2010 Gurpartap Singh. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "OAToken.h"

#import "ASIHTTPRequest.h"


// Define these API credentials as per your applicationss.

// Get here: http://twitter.com/apps
#define TWITTER_OAUTH_CONSUMER_KEY @"4XPx3kB6rLoIjqF1FoQzQ"
#define TWITTER_OAUTH_CONSUMER_SECRET @"1rzcvsRGzsAL0XwqESoc5pMR6XZZ88F3xhpjNW9zto8"

// Get here: http://dev.twitpic.com/apps/
#define TWITPIC_API_KEY @"0301f369b918e043c15a1ce473b27c2c"

// TwitPic API Version: http://dev.twitpic.com/docs/
#define TWITPIC_API_VERSION @"2"

// Enable one of the JSON Parsing libraries that the project has.
// Disable all to get raw string as response in delegate call to parse yourself.
#define TWITPIC_USE_YAJL 0
#define TWITPIC_USE_SBJSON 0
#define TWITPIC_USE_TOUCHJSON 0
#define TWITPIC_USE_JSONKIT 1
#define TWITPIC_API_FORMAT @"json"

//  Implement XML here if you wish to.
//  #define TWITPIC_USE_LIBXML 0
//  #if TWITPIC_USE_LIBXML
//    #define TWITPIC_API_FORMAT @"xml"
//  #endif


@protocol GSTwitPicEngineDelegate <NSObject>

- (void)twitpicDidFinishUpload:(NSDictionary *)response;
- (void)twitpicDidFailUpload:(NSDictionary *)error;

@end

@class ASINetworkQueue;

@interface GSTwitPicEngine : NSObject <ASIHTTPRequestDelegate, UIWebViewDelegate> {
  __unsafe_unretained  id<GSTwitPicEngineDelegate> _delegate;
  
	OAToken *_accessToken;
  
  ASINetworkQueue *_queue;
}

@property (retain) ASINetworkQueue *_queue;

+ (GSTwitPicEngine *)twitpicEngineWithDelegate:(id<GSTwitPicEngineDelegate>)theDelegate;
- (GSTwitPicEngine *)initWithDelegate:(id<GSTwitPicEngineDelegate>)theDelegate;

- (void)uploadPicture:(UIImage *)picture;
- (void)uploadPicture:(UIImage *)picture withMessage:(NSString *)message;
- (void)cancel;

@end


@interface GSTwitPicEngine (OAuth)

- (void)setAccessToken:(OAToken *)token;

@end
