//
//  AffirmConfiguration.h
//  AffirmSDK
//
//  Created by Victor Zhu on 2019/3/18.
//  Copyright © 2019 Affirm, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <WebKit/WebKit.h>
#import "AffirmConstants.h"

@class AffirmCreditCard;

NS_ASSUME_NONNULL_BEGIN

/**
 An AffirmConfiguration is a set of merchant-specific Affirm configuration settings.
 */
@interface AffirmConfiguration : NSObject

/**
 publicAPIKey Public API key.
 */
@property (nonatomic, copy, readonly) NSString *publicKey;

/**
 environment Development environment. (Production, Sandbox)
 */
@property (nonatomic, readonly) AffirmEnvironment environment;

/**
 environment User locale. (en_US, en_CA, fr_CA , etc.)
 */
@property (nonatomic, readonly) NSString *locale;

/**
 environment User country code. (USA, CAN , etc.)
 */
@property (nonatomic, readonly) NSString *countryCode;

/**
 environment Currency. (USD, CAD)
 */
@property (nonatomic, readonly) NSString *currency;

/**
 merchantName Merchant name.
 */
@property (nonatomic, copy, readonly, nullable) NSString *merchantName;

/**
 isProductionEnvironment Return a boolean whether it's production mode.
 */
@property (nonatomic, readonly) BOOL isProductionEnvironment;

/**
 creditCard Return an existing credit card.
 */
@property (nonatomic, readonly, strong, nullable) AffirmCreditCard *creditCard;

/**
 cardTip Return a text for the label below the Virtual Card image..
 */
@property (nonatomic, copy, nullable) NSString *cardTip;

/**
 isCreditCardExists Return a boolean whether credit card exists.
 */
@property (nonatomic, readonly) BOOL isCreditCardExists;

/**
 pool A WKProcessPool object represents a pool of web content processes.
 */
@property (nonatomic, strong, readonly) WKProcessPool *pool;

/**
 sharedInstance Returns the shared configuration object.
 */
@property (class, nonatomic, readonly, strong) AffirmConfiguration *sharedInstance
NS_SWIFT_NAME(shared);

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

/**
 Convenience constructor. See properties for more details.
 */
- (void)configureWithPublicKey:(NSString *)publicKey
                   environment:(AffirmEnvironment)environment
NS_SWIFT_NAME(configure(publicKey:environment:));

/**
 Convenience constructor. See properties for more details.
 */
- (void)configureWithPublicKey:(NSString *)publicKey
                   environment:(AffirmEnvironment)environment
                  merchantName:(NSString * _Nullable )merchantName
NS_SWIFT_NAME(configure(publicKey:environment:merchantName:));

/**
 Convenience constructor. See properties for more details.
 */
- (void)configureWithPublicKey:(NSString *)publicKey
                   environment:(AffirmEnvironment)environment
                        locale:(NSString *)locale
                    countryCode:(NSString *)countryCode
                      currency:(NSString *)currency
                  merchantName:(NSString * _Nullable )merchantName
NS_SWIFT_NAME(configure(publicKey:environment:locale:countryCode:currency:merchantName:));

/**
 affirmSDKVersion Current Affirm SDK version.
 */
+ (NSString *)affirmSDKVersion;

/**
 jsURL Affirm js file url
 */
- (NSString *)jsURL;

/**
 promosURL Promos endpoint url
 */
- (NSString *)promosURL;

/**
 checkoutURL Checkout endpoint url
 */
- (NSString *)checkoutURL;

/**
 trackerURL Tracker endpoint url
 */
- (NSString *)trackerURL;

/**
 environmentDescription Current environment.
 */
- (NSString *)environmentDescription;

/**
 Return all of the cookies of AffirmSDK.
 */
+ (NSArray <NSHTTPCookie *> *)cookiesForAffirm;

/**
 Delete all of the cookies of AffirmSDK.
 */
+ (void)deleteAffirmCookies;

@end

NS_ASSUME_NONNULL_END
