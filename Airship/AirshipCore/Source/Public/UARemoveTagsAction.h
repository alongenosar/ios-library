/* Copyright Airship and Contributors */

#import "UAModifyTagsAction.h"

/**
 * Removes tags. This Action is registered under the
 * names ^-t and "remove_tags_action".
 *
 * Expected argument values: NSString (single tag), NSArray (single or multiple tags), or NSDictionary (tag groups).
 * An example tag group JSON payload:
 * {
 *     "channel": {
 *         "channel_tag_group": ["channel_tag_1", "channel_tag_2"],
 *         "other_channel_tag_group": ["other_channel_tag_1"]
 *     },
 *     "named_user": {
 *         "named_user_tag_group": ["named_user_tag_1", "named_user_tag_2"],
 *         "other_named_user_tag_group": ["other_named_user_tag_1"]
 *     },
 *     "device": [ "tag", "another_tag"]
 * }
 *
 *
 * Valid situations: UASituationForegroundPush, UASituationLaunchedFromPush
 * UASituationWebViewInvocation, UASituationForegroundInteractiveButton,
 * UASituationBackgroundInteractiveButton, UASituationManualInvocation and
 * UASituationAutomation
 *
 * Default predicate: Rejects foreground pushes with visible display options
 *
 * Result value: nil
 *
 * Error: nil
 *
 * Fetch result: UAActionFetchResultNoData
 */
@interface UARemoveTagsAction : UAModifyTagsAction

/**
 * Default registry name for remove tags action.
 */
extern NSString * const UARemoveTagsActionDefaultRegistryName;

/**
 * Default registry alias for remove tags action.
 */
extern NSString * const UARemoveTagsActionDefaultRegistryAlias;

@end
