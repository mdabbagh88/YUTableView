//
//  YUTableViewItem.h
//  YUTableView
//
//  Created by Yücel Uzun on 30/01/14.
//  Copyright (c) 2014 Yücel Uzun. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum
{
    YUTableViewItemStatusNotSelected,
    YUTableViewItemStatusSelected,
    YUTableViewItemStatusSubmenuOpened,
    /** Subitem of subitem of this item is selected. Only used if "showAllItems" is NO */
    YUTableViewItemStatusParent,
    
    YUTableViewItemStatusNormal __deprecated_msg("use YUTableViewItemStatusNotSelected instead.")
} YUTableViewItemStatus;

@interface YUTableViewItem : NSObject

@property (nonatomic) YUTableViewItemStatus status;
/** All objects in "subItems" must be kind of "YUTableViewItem". */
@property (nonatomic, strong) NSArray * subItems;
/** Custom data of item, which will be passed to cell view. */
@property (nonatomic, strong) id itemData;
/** If nil, "defaultCellIdentifier" in "YUTableView" will be used. */
@property (nonatomic, strong) NSString * cellIdentifier;

/**
 @code
 YUTableViewItem * item = [[YUTableViewItem alloc] initWithData: @"Label"];
 @endcode
 @param data Custom data of the item, which will be passed to the cell view.
 */
- (id) initWithData: (id) data;
/**
 All parameters are optional.
 @code
 YUTableViewItem * item, item2;
 YUTableViewItem * item3 = [[YUTableViewItem alloc] initWithSubitems: @[item, item2] data: @{@"key":@"value"} identifier: @"Cell"];
 @endcode
 @param items Subitems of item. All objects in "items" must be kind of "YUTableViewItem". 
 @param data Custom data of item, which will be passed to cell view. If "data" is nil or wrong, can cause problems while displaying the cell.
 @param identifier Cell identifier of the cell which represents this item. If "cellIdentifier" is nil, "defaultCellIdentifier" in "YUTableView" will be used.
 */
- (id) initWithSubitems: (NSArray *) items data: (id) data identifier: (NSString *) identifier;

- (YUTableViewItem *) parent;

/** Creates a root item and sets parents of all items in array. */
+ (NSArray *) setEmptyRootItemForItemList: (NSArray *) items;

+ (void) setRootItem: (YUTableViewItem *) rootItem toMenuItems: (NSArray *) items;
+ (void) setStatusesOfItemsToNotSelected: (NSArray *) items;
+ (void) setAllSubitemSatutesToNotSelected: (YUTableViewItem *) item;

#pragma mark - deprecated methods
+ (NSArray *) initItemsFromArray: (NSArray *) items __deprecated_msg("use setEmptyRootItemForItemList: instead.");
+ (void) setRootItem: (YUTableViewItem *) rootItem menuItems: (NSArray *) items __deprecated_msg("use setRootItem:toMenuItems: instead.");
+ (void) setStatusesOfItemsToNormal: (NSArray *) items __deprecated_msg("use setStatusesOfItemsToNotSelected: instead.");
+ (void) setAllSubitemSatutesToNormal: (YUTableViewItem *) item __deprecated_msg("use setAllSubitemSatutesToNotSelected: instead.");;

@end
