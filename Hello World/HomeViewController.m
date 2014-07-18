//
//  HomeViewController.m
//  Hello World
//
//  Created by Keshav Rao on 4/12/14.
//  Copyright (c) 2014 Spritz. All rights reserved.
//

#import "HomeViewController.h"
#import <UNIRest.h>

@interface HomeViewController ()

@end

@implementation HomeViewController

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // Custom initialization
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    [[self navigationController] setNavigationBarHidden:YES animated:YES];

   
//    NSDictionary* headers = @{@"X-Mashape-Authorization": @"mBpTCcQhuQMkmYAzgvz3v3RTfFQ96vaw"};
//    NSDictionary* parameters = @{@"text": @"Merit is a concept in Buddhism/Hinduism. It is that which accumulates as a result of good deeds, acts, or thoughts and which carries over to throughout the life or the subsequent incarnations. Such merit contributes to a person's growth towards spiritual liberation. Merit can be gained in a number of ways. In addition, according to the MahayanaSutra of The Great Vows of Ksitigarbha Bodhisattva, one can transfer 1/7 merit of an act they have performed to a deceased loved one such as in the Shitro practice in order to diminish the deceased's suffering in their new existence. Pariṇāmanā(Sanskrit) may be rendered as 'transfer of merit' or 'dedication' and involves the transfer of merit as a cause to bring about an effect.", @"title": @"Hello"};
//    
//    UNIHTTPJsonResponse* response = [[UNIRest post:^(UNISimpleRequest* request) {
//        [request setUrl:@"https://textteaser.p.mashape.com/api"];
//        [request setHeaders:headers];
//        [request setParameters:parameters];
//    }] asJson];
//    
//    NSLog(@"%@", response);
//    
//    
//    
//    NSArray* sentences = [response.body.object valueForKey:@"sentences"];
//    NSLog(@"%@", sentences);
//    
//    NSError * error;
//    
//    NSMutableDictionary  * json = [NSJSONSerialization JSONObjectWithData:body options: NSJSONReadingMutableContainers error: &error];
//    NSLog(@"%@", json);
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender
{
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
