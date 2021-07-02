// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from proj.djinni

#import "ezored/net/http/EZRHttpRequest.h"

@implementation EZRHttpRequest

- (nonnull instancetype)initWithUrl:(nonnull NSString *)url
                             method:(EZRHttpMethod)method
                             params:(nonnull NSArray<EZRHttpRequestParam *> *)params
                            headers:(nonnull NSArray<EZRHttpHeader *> *)headers
                               body:(nonnull NSString *)body
{
    if (self = [super init])
    {
        _url = [url copy];
        _method = method;
        _params = [params copy];
        _headers = [headers copy];
        _body = [body copy];
    }
    return self;
}

+ (nonnull instancetype)httpRequestWithUrl:(nonnull NSString *)url
                                    method:(EZRHttpMethod)method
                                    params:(nonnull NSArray<EZRHttpRequestParam *> *)params
                                   headers:(nonnull NSArray<EZRHttpHeader *> *)headers
                                      body:(nonnull NSString *)body
{
    return [(EZRHttpRequest *)[self alloc] initWithUrl:url
                                                method:method
                                                params:params
                                               headers:headers
                                                  body:body];
}

- (NSString *)description
{
    return [NSString stringWithFormat:@"<%@ %p url:%@ method:%@ params:%@ headers:%@ body:%@>", self.class, (void *)self, self.url, @(self.method), self.params, self.headers, self.body];
}

@end
