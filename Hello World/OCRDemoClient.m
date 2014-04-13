#import "OCRDemoClient.h"


static NSString * const kApplicationId = @"SpeedStudy";
static NSString * const kPassowrd = @"mp3LWpopEgN1TkCv8asqRGUJ ";

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
