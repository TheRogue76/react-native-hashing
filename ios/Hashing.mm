#import "Hashing.h"
#import "react-native-hashing.h"

#import <React/RCTBridge+Private.h>
#import <jsi/jsi.h>

#import <React/RCTUtils.h>
#import <ReactCommon/CallInvoker.h>

#import <memory>

@implementation Hashing

RCT_EXPORT_MODULE();

+ (BOOL)requiresMainQueueSetup {
    return YES;
}

- (void)setBridge:(RCTBridge *)bridge {
    _bridge = bridge;
    _setBridgeOnMainQueue = RCTIsMainQueue();

    RCTCxxBridge *cxxBridge = (RCTCxxBridge *)self.bridge;

    if (!cxxBridge.runtime) {
        return;
    }
    installSequel(*(facebook::jsi::Runtime *)cxxBridge.runtime)
}

@end
