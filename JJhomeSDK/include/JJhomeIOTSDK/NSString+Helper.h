

#import <Foundation/Foundation.h>

@interface NSString (Helper)

// 是否包含某个字符串
- (BOOL)containsString:(NSString *)aString;

// 清空字符串中的空白字符
- (NSString *)trimString;

// 是否空字符串
- (BOOL)isEmptyString;

//浮点数处理并去掉多余的0
+(NSString *)stringDisposeWithFloat:(float)floatValue;

// 写入系统偏好
- (void)saveToNSDefaultsWithKey:(NSString *)key;

// 删除符号：()-空格
- (NSString*)trimSymbol;

// 从第一个不是零的字符开始截取字符串
- (NSString *)trimFrontZeroCharacter;

// 判断手机号码是否正确
- (BOOL)isPhoneNum;

// 判断是否是邮箱
- (BOOL)isEmail;

// 判断是否是纯数字
- (BOOL)isPureNum;

// 判断长度是否处于num1和num2之间
- (BOOL)isLengthBetween:(int)num1 and:(int)num2;
//8位及以上数字+字母的组合
- (BOOL)isLegalPsword;
@end
