/* Copyright 2017 Urban Airship and Contributors */

#import <UIKit/UIKit.h>
#import <UserNotifications/UserNotifications.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Application hooks required by Urban Airship. If `automaticSetupEnabled` is enabled
 * (enabled by default), Urban Airship will automatically integrate these calls into
 * the application by swizzling methods. If `automaticSetupEnabled` is disabled,
 * the application must call through to every method provided by this class.
 */
@interface UAAppIntegration : NSObject


///---------------------------------------------------------------------------------------
/// @name User Notification Delegate hooks
///---------------------------------------------------------------------------------------

/**
 * Must be called by the UNUserNotificationDelegate's
 * userNotificationCenter:willPresentNotification:withCompletionHandler.
 *
 * Note: This method is relevant only for iOS 10 and above.
 *
 * @param center The notification center.
 * @param response The notification response.
 * @param completionHandler A completion handler.
 */
+ (void)userNotificationCenter:(UNUserNotificationCenter *)center
   didReceiveNotificationResponse:(UNNotificationResponse *)response
            withCompletionHandler:(void(^)())completionHandler;

/**
 * Must be called by the UNUserNotificationDelegate's
 * userNotificationCenter:willPresentNotification:withCompletionHandler.
 *
 * Note: this method is relevant only for iOS 10 and above.
 *
 * @param center The notification center.
 * @param notification The notification about to be presented.
 * @param completionHandler A completion handler to be called with the desired notification presentation options.
 */
+ (void)userNotificationCenter:(UNUserNotificationCenter *)center
       willPresentNotification:(UNNotification *)notification
         withCompletionHandler:(void (^)(UNNotificationPresentationOptions options))completionHandler;


///---------------------------------------------------------------------------------------
/// @name Application Delegate hooks
///---------------------------------------------------------------------------------------

/**
 * Must be called by the UIApplicationDelegate's
 * application:didRegisterForRemoteNotificationsWithDeviceToken:.
 *
 * @param application The application instance.
 * @param deviceToken The APNS device token.
 */
+ (void)application:(UIApplication *)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken;

/**
 * Must be called by the UIApplicationDelegate's
 * application:didReceiveRemoteNotification:fetchCompletionHandler:.
 *
 * @param application The application instance.
 * @param userInfo The remote notification.
 * @param completionHandler The completion handler.
 */
+ (void)application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo fetchCompletionHandler:(void (^)(UIBackgroundFetchResult))completionHandler;

/**
 * Must be called by the UIApplicationDelegate's
 * application:didRegisterUserNotificationSettings:.
 *
 * Note: This method is relevant only for apps targeting iOS 8 and iOS 9.
 *
 * @param application The application instance.
 * @param notificationSettings The user notification settings.
 */
+ (void)application:(UIApplication *)application didRegisterUserNotificationSettings:(UIUserNotificationSettings *)notificationSettings;

/**
 * Must be called by the UIApplicationDelegate's
 * application:handleActionWithIdentifier:forRemoteNotification:completionHandler
 *
 * Note: This method is relevant only for apps targeting iOS 8 and iOS 9.
 *
 * @param application The application instance.
 * @param identifier The action identifier.
 * @param userInfo The remote notification.
 * @param handler The completion handler
 */
+ (void)application:(UIApplication *)application handleActionWithIdentifier:(NSString *)identifier forRemoteNotification:(NSDictionary *)userInfo completionHandler:(void (^)())handler;

/**
 * Must be called by the UIApplicationDelegate's
 * application:handleActionWithIdentifier:forRemoteNotification:withResponseInfo:completionHandler
 *
 * Note: This method is relevant only for apps targeting iOS 8 and iOS 9.
 *
 * @param application The application instance.
 * @param identifier The action identifier.
 * @param userInfo The remote notification.
 * @param responseInfo The user response info.
 * @param handler The completion handler
 */
+ (void)application:(UIApplication *)application handleActionWithIdentifier:(NSString *)identifier forRemoteNotification:(NSDictionary *)userInfo withResponseInfo:(nullable NSDictionary *)responseInfo completionHandler:(void (^)())handler;

@end

NS_ASSUME_NONNULL_END

