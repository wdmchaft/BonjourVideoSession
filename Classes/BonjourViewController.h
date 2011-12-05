//
//  BonjourViewController.h
//  Bonjour
//
//  Created by Wei-Meng Lee on 7/1/10.
//  Copyright __MyCompanyName__ 2010. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AsyncSocket.h"

@interface BonjourViewController : UIViewController 
    <UITableViewDelegate, 
    UITableViewDataSource,
    NSNetServiceDelegate, 
    NSNetServiceBrowserDelegate> {
	//—-outlets—-
    IBOutlet UITableView *tbView;
    IBOutlet UITextView *debug;
	
	//—-use for browsing services—-	
    NSNetServiceBrowser *browser;	
    NSMutableArray *services;
	
	IBOutlet UITextField *message;
	NSString *serviceIP;
    AsyncSocket *listenSocket;
	AsyncSocket *clientSocket;
	NSMutableArray *connectedSockets;		
}

-(void) resolveIPAddress:(NSNetService *)service;
-(void) browseServices;

//—-expose the outlets as properties—-
@property (nonatomic, retain) UITableView *tbView;
@property (nonatomic, retain) UITextView *debug;

@property (nonatomic, retain) UITextField *message;

@property (readwrite, retain) NSNetServiceBrowser *browser;
@property (readwrite, retain) NSMutableArray *services;

@property (nonatomic, retain) AsyncSocket *clientSocket;
@property (nonatomic, retain) NSString *serviceIP;

-(IBAction) btnConnect:(id)sender;
-(IBAction) btnSend:(id)sender;
-(IBAction) doneEditing:(id) sender;
+(BonjourViewController *) getRootViewController;

@end

