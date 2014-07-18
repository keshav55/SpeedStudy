#import "OCRDemoClient.h"


static NSString * const kApplicationId = @"StudyRead";
static NSString * const kPassowrd = @"m1qIV6DDxBZDJ4FPGJW5jjbJ";

@implementation OCRDemoClient

+ (instancetype)sharedClient
{
	static OCRDemoClient* sharedClient;
	static dispatch_once_t onceToken;
	dispatch_once(&onceToken, ^{
		sharedClient = [[OCRDemoClient alloc] initWithApplicationId:kApplicationId password:kPassowrd];
	});
	
	return sharedClient;
}

@end
