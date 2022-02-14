#import <React/RCTBridgeModule.h>

#import "react-native-hashing.h"

@interface Hashing : NSObject <RCTBridgeModule>

@property(nonatomic, assign) BOOL setBridgeOnMainQueue;

@end
