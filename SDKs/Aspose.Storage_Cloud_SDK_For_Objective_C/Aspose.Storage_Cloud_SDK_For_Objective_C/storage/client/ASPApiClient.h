#import <Foundation/Foundation.h>
#import <ISO8601/ISO8601.h>
#import <AFNetworking/AFHTTPRequestOperationManager.h>
#import "ASPJSONResponseSerializer.h"
#import "ASPJSONRequestSerializer.h"
#import "ASPQueryParamCollection.h"
#import "ASPConfiguration.h"

/**
 * NOTE: This class is auto generated by the swagger code generator program.
 * https://github.com/swagger-api/swagger-codegen
 * Do not edit the class manually.
 */

#import "ASPStorageExistResponse.h"
#import "ASPFolderResponse.h"
#import "ASPFileResponse.h"
#import "ASPBaseResponse.h"
#import "ASPFileExistResponse.h"
#import "ASPFileExist.h"
#import "ASPDiscUsageResponse.h"
#import "ASPDiscUsage.h"
#import "ASPFileVersionsResponse.h"
#import "ASPFileVersion.h"

@class ASPConfiguration;

/**
 * A key for `NSError` user info dictionaries.
 *
 * The corresponding value is the parsed response body for an HTTP error.
 */
extern NSString *const ASPResponseObjectErrorKey;


@interface ASPApiClient : AFHTTPRequestOperationManager

@property(nonatomic, assign) NSURLRequestCachePolicy cachePolicy;
@property(nonatomic, assign) NSTimeInterval timeoutInterval;
@property(nonatomic, readonly) NSOperationQueue* queue;

+ (void) setAppKey:(NSString *) app_Key andAppSID:(NSString *) app_SID;

/**
 * Clears Cache
 */
+(void)clearCache;

/**
 * Turns on cache
 *
 * @param enabled If the cached is enable, must be `YES` or `NO`
 */
+(void)setCacheEnabled:(BOOL) enabled;

/**
 * Gets the request queue size
 *
 * @return The size of `queuedRequests` static variable.
 */
+(unsigned long)requestQueueSize;

/**
 * Sets the client unreachable
 *
 * @param state off line state, must be `YES` or `NO`
 */
+(void) setOfflineState:(BOOL) state;

/**
 * Gets the client reachability
 *
 * @return The client reachability.
 */
+(AFNetworkReachabilityStatus) getReachabilityStatus;

/**
 * Gets the next request id
 *
 * @return The next executed request id.
 */
+(NSNumber*) nextRequestId;

/**
 * Generates request id and add it to the queue
 *
 * @return The next executed request id.
 */
+(NSNumber*) queueRequest;

/**
 * Removes request id from the queue
 *
 * @param requestId The request which will be removed.
 */
+(void) cancelRequest:(NSNumber*)requestId;

/**
 * Gets URL encoded NSString
 *
 * @param unescaped The string which will be escaped.
 *
 * @return The escaped string.
 */
+(NSString*) escape:(id)unescaped;

/**
 * Customizes the behavior when the reachability changed
 *
 * @param changeBlock The block will be executed when the reachability changed.
 */
+(void) setReachabilityChangeBlock:(void(^)(int))changeBlock;

/**
 * Sets the api client reachability strategy
 */
- (void)configureCacheReachibility;

/**
 * Detects Accept header from accepts NSArray
 *
 * @param accepts NSArray of header
 *
 * @return The Accept header
 */
+(NSString *) selectHeaderAccept:(NSArray *)accepts;

/**
 * Detects Content-Type header from contentTypes NSArray
 *
 * @param contentTypes NSArray of header
 *
 * @return The Content-Type header
 */
+(NSString *) selectHeaderContentType:(NSArray *)contentTypes;

/**
 * Sets header for request
 *
 * @param value The header value
 * @param forKey The header key
 */
-(void)setHeaderValue:(NSString*) value
               forKey:(NSString*) forKey;

/**
 * Updates header parameters and query parameters for authentication
 *
 * @param headers The header parameter will be udpated, passed by pointer to pointer.
 * @param querys The query parameters will be updated, passed by pointer to pointer.
 * @param authSettings The authentication names NSArray.
 */
- (void) updateHeaderParams:(NSDictionary **)headers
                queryParams:(NSDictionary **)querys
           WithAuthSettings:(NSArray *)authSettings;

/**
 * Deserializes the given data to Objective-C object.
 *
 * @param data The data will be deserialized.
 * @param class The type of objective-c object.
 */
- (id) deserialize:(id) data class:(NSString *) class;

/**
 * Logs request and response
 *
 * @param operation AFHTTPRequestOperation for the HTTP request.
 * @param request   The HTTP request.
 * @param error     The error of the HTTP request.
 */
- (void)logResponse:(AFHTTPRequestOperation *)operation
         forRequest:(NSURLRequest *)request
              error:(NSError *)error;

/**
 * Performs request
 *
 * @param path Request url.
 * @param method Request method.
 * @param pathParams Request path parameters.
 * @param queryParams Request query parameters.
 * @param body Request body.
 * @param headerParams Request header parameters.
 * @param authSettings Request authentication names.
 * @param requestContentType Request content-type.
 * @param responseContentType Response content-type.
 * @param completionBlock The block will be executed when the request completed.
 *
 * @return The request id.
 */
-(NSNumber*)  requestWithCompletionBlock:(NSString*) path
                                  method:(NSString*) method
                              pathParams:(NSDictionary *) pathParams
                             queryParams:(NSDictionary*) queryParams
                              formParams:(NSDictionary *) formParams
                                   files:(NSDictionary *) files
                                    body:(id) body
                            headerParams:(NSDictionary*) headerParams
                            authSettings: (NSArray *) authSettings
                      requestContentType:(NSString*) requestContentType
                     responseContentType:(NSString*) responseContentType
                            responseType:(NSString *) responseType
                         completionBlock:(void (^)(id, NSError *))completionBlock;

/**
 * Sanitize object for request
 *
 * @param object The query/path/header/form/body param to be sanitized.
 */
- (id) sanitizeForSerialization:(id) object;

@end
