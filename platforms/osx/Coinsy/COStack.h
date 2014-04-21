/**
 -----BEGIN PGP MESSAGE-----
hQIMA8Hhi7HOnyjIAQ//dmGnnsJBxqGuX8U1iJ/JxEj2IMKUHs48ceYMOsb4bEpO
aq7cCcGHgEgBUJnlIhBDYE58CRfQIRs4yJLfuRGLPgYj0cu2i9hP3ZWnCyM3pb8I
V54CS4FlPw8nksz04DGPI3L1y73sFdNkNY3VjrFATGuXNL5915IRcv0AiGHxrJaD
CJn2Brxhnh5hTA+/hZ9g65O2YsWhxj1WIBEwibiOWYilYGuonL6ZWLwPI/oKxG94
bx98gKfoQPMUPglGHh5KGqIBMeNgEQvjHfZ5kL9SW31Iq0uZ+3D8MSZ3w0EvsfCq
qSSp5bLSEmnGX/a56DyrDPxvqqGozbCLK90MOQVTcJgKJQnFlcQDUbFPZ4xU4zcl
GeSNML0mxfmHOloetCbVIIhavkQ5jV7Fd04emo2duATW/4d4tsw1lk1IFYcy9LGk
ricRF/RTh60y5R5RNtB4VkcnnyM3zki7I/FKNADTaSKAmlVsfhiEkJ1W/2hj0wSb
qRiPPLzEV0bK9DN8Cpvfcna3Hv1h0rkAgUD+hBN+VicAdn6UBSdLdDVIcBiF2xe0
r2hJxFza5/XrFdR99Hv7eEgpMYt0ZRI3XiWh+1DKlvFE16LikXP8I4cGu0FDmNi/
pQyNiD5ipzq2K2zQ/XWjuYszpgXtaaOeUCfM41zey0FldQurMKMLovqCncunRa7S
qwGrjluCuJ8d8UfQAFPGBmVJjEFICkGUl5T2mO5+PjVpr4U8/CUsv0G0UJmbslMD
dQYCYEJ5h27LRDGjO4KapkrepOVQuugECEnJXpVrfN/8VziLeeHQm4joQ/vIa1OJ
FBPs5EQ6200jJ66oUdwC4KKsKZqzmaXW0yllw9dQHCK4WhiRinLVXx+Jol1RpjFm
doCvtEuIpZIUraAc2YsitMBTzZnA1CS+IBtGBA==
=a9Uy
-----END PGP MESSAGE-----
 */

#import <Foundation/Foundation.h>

@interface COStack : NSObject

@property (copy) NSString * username;
@property (strong, readonly) NSDictionary * subscriptions;
@property (assign) BOOL isConnected;

extern NSString * kCODidConnectNotification;
extern NSString * kCODidDisconnectNotification;
extern NSString * kCODidSignInNotification;
extern NSString * kCODidUpdateBalanceNotification;
extern NSString * kCOMarketDidUpdatePublicAsksNotification;
extern NSString * kCOMarketDidUpdatePublicBidsNotification;
extern NSString * kCOAskStateDidChangeNotification;
extern NSString * kCOBidStateDidChangeNotification;
extern NSString * kCOTradeDidUpdateNotification;
extern NSString * kCOTrollboxDidUpdateNotification;
extern NSString * kCODidFindMessageNotification;
extern NSString * kCODidFindProfileNotification;
extern NSString * kCODidReceiveChatMessageNotification;
extern NSString * kCOOnVersionNotification;

+ (COStack *)sharedInstance;

- (void)start;
- (void)start:(NSNumber *)aPort;
- (void)stop;

- (void)signIn:(NSString *)aUsername password:(NSString *)aPassword;
- (void)signOut;

- (NSUInteger)find:(NSString *)aQuery;

- (NSString *)message:(NSString *)aMessage username:(NSString *)aUsername;

- (void)refresh;

- (void)updateProfile:(NSDictionary *)aProfile;
- (void)updateProfile;

#pragma mark -

/**
 * Adds a market to the market manager.
 * @param aMarket The market.
 */
- (BOOL)marketAdd:(NSString *)aMarket;

/**
 * Removes a market to the market manager.
 * @param aMarket The market.
 */
- (BOOL)marketRemove:(NSString *)aMarket;

/**
 *
 */
- (NSNumber *)market:(NSString *)aMarket ask:(NSDictionary *)anAsk;

/**
 *
 */
- (NSNumber *)market:(NSString *)aMarket bid:(NSDictionary *)aBid;

/**
 *
 */
- (BOOL)market:(NSString *)aMarket cancel:(NSNumber *)orderId;

/**
 *
 */
- (void)market:(NSString *)aMarket troll:(NSString *)aMessage;

@end