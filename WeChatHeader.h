//
//  WeChatHeader.h
//  WechatMacMessageRobotFramework
//
//  Created by sylar on 2021/3/16.
//
@interface MMService : NSObject

@end

@interface FFProcessReqsvrZZ : MMService
- (id)FFProcessTReqZZ:(id)arg1 toUsrName:(id)arg2 msgText:(id)arg3 atUserList:(id)arg4;
@end


@interface MMChatMessageDataSource : NSObject
- (void)onAddMsg:(id)arg1 msgData:(id)arg2;
@end

#pragma mark - Desperate
@interface MessageService : NSObject
- (void)downloadThumb:(id)arg1;
- (void)reportAppFeedLiveWithInfo:(id)arg1;
- (void)reportAppFeed:(id)arg1 withAction:(int)arg2 withInfo:(id)arg3;
- (id)getFinderFeedLiveWebUrl:(id)arg1 withScene:(int)arg2;
- (id)getFinderFeedWebUrl:(id)arg1 withScene:(int)arg2;
- (BOOL)supportFinderFeed;
- (id)tempWeAppLogDataPath;
- (void)cleanTempWeAppFilePath;
- (void)addTempWeAppFilePath:(id)arg1;
- (void)preprocessingIPXXMessage:(id)arg1;
- (id)msgListDuplicateProcess:(id)arg1 chatName:(id)arg2 bFunFlag:(BOOL)arg3;
- (BOOL)isMsgDuplicateProcess:(id)arg1 chatName:(id)arg2 bFunFlag:(BOOL)arg3;
- (BOOL)isMsgSpecialProcess:(id)arg1;
- (void)setupDownloadMgr;
- (void)proxySettingsDidChange:(id)arg1;
- (id)ForwardFavoritesItem:(id)arg1 withThumbnailData:(id)arg2 thumbnailSize:(struct CGSize)arg3 imageData:(id)arg4 toUserName:(id)arg5;
- (id)ForwardFavoritesItem:(id)arg1 toUserName:(id)arg2;
- (id)forwardAppReferMsgMessage:(id)arg1 toUser:(id)arg2 errMsg:(id *)arg3;
- (id)forwardAppImageMessage:(id)arg1 toUser:(id)arg2 errMsg:(id *)arg3;
- (id)forwardVideoMessageFromFav:(id)arg1 toUser:(id)arg2 errMsg:(id *)arg3;
- (id)forwardVideoMessage:(id)arg1 toUser:(id)arg2 errMsg:(id *)arg3;
- (id)ForwardMessage:(id)arg1 withReaderWrap:(id)arg2 toUser:(id)arg3;
- (id)ForwardMessage:(id)arg1 toUser:(id)arg2 errMsg:(id *)arg3;
- (unsigned char)SendTextMessageWithString:(id)arg1 toUser:(id)arg2;
- (void)addAppMsgToSendQueue:(id)arg1 toUserName:(id)arg2 scene:(unsigned int)arg3;
- (id)forwardAppMsgMessage:(id)arg1 toUser:(id)arg2 errMsg:(id *)arg3;
- (id)forwardAppEmojiMessage:(id)arg1 toUser:(id)arg2 errMsg:(id *)arg3;
- (id)forwardAppFileMessage:(id)arg1 toUser:(id)arg2 errMsg:(id *)arg3;
- (id)forwardEmojiMessage:(id)arg1 toUser:(id)arg2 errMsg:(id *)arg3;
- (id)forwardImageMessage:(id)arg1 toUser:(id)arg2 errMsg:(id *)arg3;
- (id)forwardTransferTextMessage:(id)arg1 toUser:(id)arg2 errMsg:(id *)arg3;
- (id)forwardTextMessage:(id)arg1 toUser:(id)arg2 errMsg:(id *)arg3;
- (void)notifyUIAndSessionOnMainThread:(id)arg1 withMsg:(id)arg2;
- (id)createNewMessage:(id)arg1 withUserName:(id)arg2;
- (id)resendAppReferMessage:(id)arg1 toUser:(id)arg2;
- (void)ResendMsg:(id)arg1 toUser:(id)arg2;
- (id)sendAppReferMessage:(id)arg1 withText:(id)arg2 fromUsrName:(id)arg3 toUsrName:(id)arg4 atUserList:(id)arg5;
- (id)sendWebStreamVideoMessage:(id)arg1 toUsrName:(id)arg2;
- (id)SendVideoMessage:(id)arg1 toUsrName:(id)arg2 videoInfo:(id)arg3 msgType:(unsigned int)arg4 refMesageData:(id)arg5;
- (void)asyncCompressVideoInGlobalQueue:(id)arg1 videoDataInfo:(id)arg2 toUsrName:(id)arg3;
- (void)sendChatSyncAppMsg:(id)arg1;
- (id)SendSolitaireAppMsg:(id)arg1;
- (id)forwardSolitaireAppMsg:(id)arg1 toUsr:(id)arg2 errMsg:(id *)arg3;
- (id)resendSolitaireAppMsg:(id)arg1 toUsr:(id)arg2 errMsg:(id *)arg3;
- (id)CreateAppSolitaireTextMsgWithSolitaire:(id)arg1;
- (id)SendFeedAppMsgTo:(id)arg1 withFavoritesItem:(id)arg2;
- (id)SendNoteAppMsgTo:(id)arg1 withFavoritesItem:(id)arg2;
- (id)SendRecordAppMsgTo:(id)arg1 withFavoritesItem:(id)arg2;
- (void)copySourceFilePath:(id)arg1 WithDataList:(id)arg2;
- (id)SendFileAppMsgTo:(id)arg1 fileName:(id)arg2 filePath:(id)arg3;
- (id)SendGifAppMsgFromUsr:(id)arg1 toUser:(id)arg2 gifFilePath:(id)arg3;
- (id)SendGifFileMsgFromUsr:(id)arg1 toUser:(id)arg2 gifFileName:(id)arg3 gifFilePath:(id)arg4;
- (id)getEmoticonMsgContentWithMD5:(id)arg1 emoticonType:(unsigned int)arg2;
- (id)_getWWNamecardMsgContentForContact:(id)arg1;
- (id)_getNamecardMsgContentForContact:(id)arg1;
- (id)SendLocationMsgFromUser:(id)arg1 toUser:(id)arg2 withLatitude:(double)arg3 longitude:(double)arg4 poiName:(id)arg5 label:(id)arg6;
- (id)SendNamecardMsgFromUser:(id)arg1 toUser:(id)arg2 containingContact:(id)arg3;
- (id)SendStickerStoreEmoticonMsgFromUsr:(id)arg1 toUsrName:(id)arg2 md5:(id)arg3 productID:(id)arg4;
- (id)SendEmoticonMsgFromUsr:(id)arg1 toUsrName:(id)arg2 md5:(id)arg3 emoticonType:(unsigned int)arg4;
- (id)SendImgMessage:(id)arg1 toUsrName:(id)arg2 thumbImgData:(id)arg3 midImgData:(id)arg4 imgData:(id)arg5 imgInfo:(id)arg6;
- (id)SendTextMessage:(id)arg1 toUsrName:(id)arg2 msgText:(id)arg3 atUserList:(id)arg4;
- (id)SendAppMusicMessageFromUser:(id)arg1 toUsrName:(id)arg2 withTitle:(id)arg3 url:(id)arg4 description:(id)arg5 thumbnailData:(id)arg6;
- (id)SendAppURLMessageFromUser:(id)arg1 toUsrName:(id)arg2 withTitle:(id)arg3 url:(id)arg4 description:(id)arg5 thumbnailData:(id)arg6;
- (id)SendAppURLMessageFromUser:(id)arg1 toUsrName:(id)arg2 withTitle:(id)arg3 url:(id)arg4 description:(id)arg5 thumbUrl:(id)arg6 sourceUserName:(id)arg7 sourceDisplayName:(id)arg8;
- (void)processAddMsg:(id)arg1 sessionMsgList:(id)arg2 isFirstSync:(BOOL)arg3 isFunctionMsg:(BOOL)arg4;
- (void)FFToNameFavChatZZ:(id)arg1 sessionMsgList:(id)arg2;
- (void)processSysMsg:(id)arg1;
- (void)processVoipInviteMsg:(id)arg1;
- (void)processYoMsg:(id)arg1;
- (void)processNewXMLMsg:(id)arg1 sessionMsgList:(id)arg2;
- (void)onRevokeRoomHistory:(id)arg1;
- (void)addTemplateNewXmlMsg:(id)arg1 sessionMsgList:(id)arg2;
- (void)addSendCommand:(id)arg1;
- (void)addMarkFunction:(id)arg1;
- (void)addChatList:(id)arg1;
- (void)addMarkRead:(id)arg1 createTime:(unsigned int)arg2;
- (void)addQuitSession:(id)arg1;
- (void)addEnterSession:(id)arg1;
- (void)addMarkUnRead:(id)arg1 createTime:(unsigned int)arg2;
- (void)processStatusNotify:(id)arg1 map:(id)arg2;
- (void)OnSyncModMsgStatus:(id)arg1;
- (void)OnSyncBatchAddFunctionMsgs:(id)arg1 isFirstSync:(BOOL)arg2;
- (void)FFImgToOnFavInfoInfoVCZZ:(id)arg1 isFirstSync:(BOOL)arg2;
- (void)onServiceClearData;
- (void)setupMacHelperOnMainThread;
- (void)onServiceInit;
- (id)init;
- (void)notifyMsgResendOnMainThread:(id)arg1 msgData:(id)arg2;
- (void)notifyUnreadCntChangeOnMainThread:(id)arg1;
- (void)notifyAddMsgListForSessionOnMainThread:(id)arg1;
- (void)notifyDelAllMsgOnMainThread:(id)arg1;
- (void)notifyMsgDeletedForSessionOnMainThread:(id)arg1;
- (void)notifyDelMsgOnMainThread:(id)arg1 msgData:(id)arg2 isRevoke:(BOOL)arg3;
- (void)notifyAddRevokePromptMsgOnMainThread:(id)arg1 msgData:(id)arg2;
- (void)notifyRevokePatMsgOnMainThread:(id)arg1 n64MsgId:(long long)arg2;
- (void)notifyModMsgOnMainThread:(id)arg1 msgData:(id)arg2;
- (void)notifyChatSyncMessagesMergedOnMainThread:(id)arg1;
- (void)notifyChatSyncMsgsOnMainThread:(id)arg1 msgList:(id)arg2;
- (void)notifyAddMsgOnMainThread:(id)arg1 msgData:(id)arg2;
- (void)notifyNewMsgNotificationOnMainThread:(id)arg1 msgData:(id)arg2;
- (void)AddTestMsg:(id)arg1 msgData:(id)arg2;
- (void)AddLocalMsg:(id)arg1 msgData:(id)arg2;
- (BOOL)deleteAllMsg:(id)arg1 isManual:(BOOL)arg2;
- (BOOL)deleteAllMsg:(id)arg1;
- (BOOL)DeleteMsgList:(id)arg1 chatName:(id)arg2 isManual:(BOOL)arg3;
- (BOOL)DeleteMsgList:(id)arg1 chatName:(id)arg2;
- (void)DelMsg:(id)arg1 msgList:(id)arg2 isDelAll:(BOOL)arg3 isManual:(BOOL)arg4;
- (void)DelRevokedMsg:(id)arg1 msgData:(id)arg2;
- (BOOL)UpdateUnReadStateWithPatMessage:(id)arg1;
- (BOOL)UpdateCreateTimeWithMessage:(id)arg1;
- (BOOL)UpdateDataMd5WithMessage:(id)arg1;
- (BOOL)UpdateImageSizeWithMessage:(id)arg1;
- (void)UpdateReferMsgAsRevoked:(id)arg1 chatName:(id)arg2;
- (BOOL)UpdateUploadAndDownloadStatusInDBWithMessage:(id)arg1;
- (BOOL)UpdateImageInformationInDBWithMessage:(id)arg1;
- (BOOL)UpdateVideoInformationInDBWithMessage:(id)arg1;
- (BOOL)UpdateVideoThumbInfoInDBWithMessage:(id)arg1;
- (BOOL)UpdateFileInformationInDBWithMessage:(id)arg1;
- (BOOL)UpdateTranslateStatusInDBWithMessage:(id)arg1;
- (BOOL)UpdateVoiceTextInDBWithMessage:(id)arg1;
- (void)ClearUnReadForSync:(id)arg1 ToCreateTime:(unsigned int)arg2;
- (void)ClearUnRead:(id)arg1 FromCreateTime:(unsigned int)arg2 ToCreateTime:(unsigned int)arg3;
- (void)ModifyMsgData:(id)arg1 msgData:(id)arg2;
- (void)ModifyMsgDataField:(id)arg1 msgData:(id)arg2 bitSet:(unsigned int)arg3;
- (void)CheckDownloadStatus:(id)arg1;
- (void)CheckUploadStatus:(id)arg1;
- (void)CheckReferMessageAsRevoked:(id)arg1 chatName:(id)arg2;
- (id)ExistingSvrIdList:(id)arg1 chatName:(id)arg2;
- (BOOL)IsSvrIdExists:(unsigned long long)arg1 chatName:(id)arg2;
- (BOOL)HasMsgInChat:(id)arg1;
- (unsigned int)GetUnReadCount:(id)arg1;
- (id)GetMsgData:(id)arg1 svrId:(unsigned long long)arg2 shouldCheck:(BOOL)arg3 shouldCheckRefer:(BOOL)arg4;
- (id)GetMsgData:(id)arg1 svrId:(unsigned long long)arg2 shouldCheck:(BOOL)arg3;
- (id)GetMsgData:(id)arg1 svrId:(unsigned long long)arg2;
- (id)GetMsgData:(id)arg1 localId:(unsigned int)arg2 shouldCheck:(BOOL)arg3;
- (id)GetMsgData:(id)arg1 localId:(unsigned int)arg2;
- (id)GetAllMsgWithChatName:(id)arg1 messageType:(unsigned int)arg2;
- (id)GetMsgListWithChatName:(id)arg1 fromMinCreateTime:(unsigned int)arg2 localId:(unsigned long long)arg3 limitCnt:(unsigned int)arg4 hasMore:(char *)arg5;
- (id)GetMsgListWithChatName:(id)arg1 fromCreateTime:(unsigned int)arg2 localId:(unsigned long long)arg3 limitCnt:(unsigned int)arg4 hasMore:(char *)arg5 messageTypes:(id)arg6 sortAscend:(BOOL)arg7;
- (id)GetMsgListWithChatName:(id)arg1 fromCreateTime:(unsigned int)arg2 localId:(unsigned long long)arg3 limitCnt:(unsigned int)arg4 hasMore:(char *)arg5 sortAscend:(BOOL)arg6;
- (id)GetLastAppMsg:(id)arg1 shouldCheck:(BOOL)arg2;
- (id)GetLastAppMsg:(id)arg1;
- (id)GetLastMsg:(id)arg1 shouldCheck:(BOOL)arg2;
- (id)GetLastMsg:(id)arg1;
- (unsigned int)GetLastMsgCreateTime:(id)arg1;
- (unsigned int)GetLastMsgLocalId:(id)arg1;
- (id)GetMsgDBWithIdentifier:(id)arg1;
- (id)GetMsgDBIndetifier:(id)arg1;
- (id)GetMsgDBName:(id)arg1;
- (id)GetMsgDB:(id)arg1;
- (id)GetImgOrVideoNextMsg:(id)arg1 FromID:(unsigned int)arg2 CreateTime:(unsigned int)arg3 Limit:(unsigned int)arg4;
- (id)GetImgOrVideoLastMsg:(id)arg1 FromID:(unsigned int)arg2 CreateTime:(unsigned int)arg3 Limit:(unsigned int)arg4;
- (BOOL)isPreviewVideoMsgDownloading:(id)arg1;
- (BOOL)isPreviewImageMsgDownloading:(id)arg1;
- (id)GetFileMsgList:(id)arg1 arrFTSMessageData:(id)arg2;
- (long long)GetAppMsgListCount:(id)arg1 minMesLocalId:(unsigned int)arg2;
- (id)GetAppMsgList:(id)arg1 minMesLocalId:(unsigned int)arg2 limitCnt:(unsigned int)arg3;
- (void)onRecordMsgUploadCDNModMsgByBitSet:(id)arg1 MsgWrap:(id)arg2 BitSet:(unsigned int)arg3;
- (void)notifyAppMsgDownloadProgress:(id)arg1 msgData:(id)arg2 downloadedBytes:(int)arg3 totalBytes:(int)arg4;
- (void)onAppMsgDownloadExpired:(id)arg1 msgData:(id)arg2 type:(int)arg3;
- (void)onAppMsgDownloadFinish:(id)arg1 msgData:(id)arg2 isSuccess:(BOOL)arg3 type:(int)arg4;
- (void)notifyAppMsgUploadProgress:(id)arg1 msgData:(id)arg2 uploadedBytes:(int)arg3 totalBytes:(int)arg4;
- (void)onAppMsgSendFinish:(id)arg1 msgData:(id)arg2 isSuccess:(BOOL)arg3;
- (void)onVoiceFailedToParseXMLWhenDownloading:(id)arg1;
- (void)onVoiceDowloadFinished:(id)arg1 isSuccess:(BOOL)arg2 isNeedSave:(BOOL)arg3 offset:(unsigned long long)arg4;
- (void)onVoiceUploadCanceledWhenDownloading:(id)arg1;
- (void)notifyVideoMsgUploadProgress:(id)arg1 msgData:(id)arg2 uploadedBytes:(int)arg3 totalBytes:(int)arg4;
- (void)onVideoMsgSendFinish:(id)arg1 msgData:(id)arg2 isSuccess:(BOOL)arg3;
- (void)notifyImgMsgUploadProgress:(id)arg1 msgData:(id)arg2 uploadedBytes:(int)arg3 totalBytes:(int)arg4;
- (void)onImgMsgSendFinish:(id)arg1 msgData:(id)arg2 isSuccess:(BOOL)arg3;
- (void)onTextMsgSendFinish:(id)arg1 msgData:(id)arg2 isSuccess:(BOOL)arg3;
- (void)onEmoticonMsgSendFinish:(id)arg1 msgData:(id)arg2 isSuccess:(BOOL)arg3;
- (void)_finishDownloadImageWithMessage:(id)arg1 type:(int)arg2 isSuccess:(BOOL)arg3;
- (void)cdnDownloadMgrDidFinishedDownloadWithChatName:(id)arg1 localID:(unsigned int)arg2 recordMsgData:(id)arg3 type:(int)arg4 isSuccess:(BOOL)arg5;
- (void)cdnDownloadMgrDidFailedDownloadWithChatName:(id)arg1 localID:(unsigned int)arg2 recordMsgData:(id)arg3 type:(int)arg4;
- (void)cdnDownloadMgrDidFinishedDownloadWithChatName:(id)arg1 localID:(unsigned int)arg2 recordMsgData:(id)arg3 type:(int)arg4;
- (void)cdnDownloadMgrDidCanceledDownloadWithCdnTask:(id)arg1;
- (void)cdnDownloadMgrDidFailedDownloadWithCdnTask:(id)arg1;
- (void)cdnDownloadMgrDidFinishedDownloadWithCdnTask:(id)arg1;
- (void)cdnDownloadMgrDownloaded:(int)arg1 of:(int)arg2 withMessage:(id)arg3 type:(int)arg4 tryShow:(BOOL)arg5;
- (void)downloadAppMessage:(id)arg1;
- (BOOL)isAppMsgDownloading:(id)arg1;
- (BOOL)isAppMsgUploading:(id)arg1;
- (void)downloadVoiceWithMessage:(id)arg1;
- (id)getUploadingVideoMessageForUniqueID:(id)arg1;
- (id)getDownloadingVideoMessageForUniqueID:(id)arg1;
- (void)cancelUploadVideoWithMessage:(id)arg1;
- (void)cancelDownloadVideoWithMessage:(id)arg1;
- (BOOL)downloadVideoWithMessage:(id)arg1;
- (BOOL)isVideoMsgDownloading:(id)arg1;
- (BOOL)isVideoMsgUploading:(id)arg1;
- (void)fileReTransferOfChat:(id)arg1 forMessage:(long long)arg2;
- (id)getUploadingFileMessageForUniqueID:(id)arg1;
- (id)getDownloadingFileMessageForUniqueID:(id)arg1;
- (void)cancelUploadFileWithMessage:(id)arg1;
- (void)cancelDownloadFileWithMessage:(id)arg1;
- (void)_startDownloadFileWithMessage:(id)arg1 destinationPath:(id)arg2 signature:(id)arg3 fakeAeskey:(id)arg4 fakeSignature:(id)arg5;
- (void)downloadFileWithMessage:(id)arg1 chatName:(id)arg2 destinationPath:(id)arg3;
- (BOOL)isImgMsgDownloading:(id)arg1;
- (BOOL)isImgMsgUploading:(id)arg1;
- (BOOL)isEmojiMsgUploading:(id)arg1;
- (BOOL)isTextMsgUploading:(id)arg1;
- (void)cleanDownloadTask:(id)arg1;
- (id)GetMsgList:(id)arg1 arrFTSMessageData:(id)arg2;
- (id)GetMsgListWithChatName:(id)arg1 minCreateTime:(unsigned int)arg2 limitCnt:(unsigned int)arg3;
- (id)GetMsgListWithChatName:(id)arg1 minMesLocalId:(unsigned int)arg2 limitCnt:(unsigned int)arg3;
- (id)GetMaxLocalIdMsg:(id)arg1;
- (id)SearchWithKeyword:(id)arg1 chatName:(id)arg2 minMesLocalID:(unsigned int)arg3 limitCount:(unsigned int)arg4;
- (id)getMsgDeletion:(id)arg1 mesSvrId:(long long)arg2 msgDB:(id)arg3;
- (id)getLastMsgDeletion:(id)arg1 msgDB:(id)arg2;
- (BOOL)deleteMsgGapBy:(id)arg1;
- (BOOL)updateMsgGapBy:(id)arg1;
- (BOOL)deleteMsgGapEarlierThan:(unsigned int)arg1;
- (id)getMsgGapsFrom:(unsigned int)arg1 to:(unsigned int)arg2 chat:(id)arg3;
- (void)addMsgGapForSessions:(id)arg1 startTime:(unsigned int)arg2 endTime:(unsigned int)arg3;
- (int)changeType:(id)arg1 oldMsg:(id)arg2;
- (id)getOldMsg:(long long)arg1 oldMsgList:(id)arg2;
- (void)movePathsFromOldMessage:(id)arg1 toNewMessage:(id)arg2;
- (void)sendChatSyncNewXml:(id)arg1 startTime:(unsigned int)arg2 endTime:(unsigned int)arg3 sessionName:(id)arg4 identifier:(id)arg5 limit:(unsigned int)arg6;
- (BOOL)insertMsgList:(id)arg1 chatName:(id)arg2 toDB:(id)arg3 oldMsgList:(id)arg4;
- (id)genMsgDataFromBakChatMsgItem:(id)arg1;
- (void)updateSession:(id)arg1 chatName:(id)arg2 toDB:(id)arg3;
- (BOOL)isInMessageException:(id)arg1 chatName:(id)arg2 toDB:(id)arg3 sender:(id)arg4;
- (id)getAdjustMessage:(id)arg1 chatName:(id)arg2 toDB:(id)arg3 oldMsgList:(id)arg4;
- (id)getFilterDeleteMessage:(id)arg1 chatName:(id)arg2 toDB:(id)arg3;
- (id)getFilterUnSupportMessage:(id)arg1;
- (id)parseAndSortSyncMsgList:(id)arg1;
- (void)OnSyncBatchBakChatMsg:(id)arg1 sender:(id)arg2 message:(id)arg3 msgGap:(id)arg4;
@end

@interface IMessageExt : NSObject
- (void)onMsgDownloadThumbOK:(NSString *)arg1 msgData:(id)arg2;
@end

@interface MMServiceCenter : NSObject
+ (id)defaultCenter;
- (id)getService:(Class)arg1;
@end


@interface SKBuiltinString_t : NSObject
@property(retain, nonatomic, setter=SetString:) NSString *string; // @synthesize string;
@end

@interface SKBuiltinBuffer_t : NSObject
@property (nonatomic, strong) NSData *buffer;
@end

@interface AddMsg : NSObject
{
    unsigned int hasMsgId:1;
    unsigned int hasFromUserName:1;
    unsigned int hasToUserName:1;
    unsigned int hasMsgType:1;
    unsigned int hasContent:1;
    unsigned int hasStatus:1;
    unsigned int hasImgStatus:1;
    unsigned int hasImgBuf:1;
    unsigned int hasCreateTime:1;
    unsigned int hasMsgSource:1;
    unsigned int hasPushContent:1;
    unsigned int hasNewMsgId:1;
    unsigned int hasMsgSeq:1;
    int msgId;
    int msgType;
    unsigned int status;
    unsigned int imgStatus;
    unsigned int createTime;
    unsigned int msgSeq;
    SKBuiltinString_t *fromUserName;
    SKBuiltinString_t *toUserName;
    SKBuiltinString_t *content;
    SKBuiltinBuffer_t *imgBuf;
    NSString *msgSource;
    NSString *pushContent;
    long long newMsgId;
}

+ (id)parseFromData:(id)arg1;
@property(nonatomic, setter=SetMsgSeq:) unsigned int msgSeq; // @synthesize msgSeq;
@property(readonly, nonatomic) BOOL hasMsgSeq; // @synthesize hasMsgSeq;
@property(nonatomic, setter=SetNewMsgId:) long long newMsgId; // @synthesize newMsgId;
@property(readonly, nonatomic) BOOL hasNewMsgId; // @synthesize hasNewMsgId;
@property(retain, nonatomic, setter=SetPushContent:) NSString *pushContent; // @synthesize pushContent;
@property(readonly, nonatomic) BOOL hasPushContent; // @synthesize hasPushContent;
@property(retain, nonatomic, setter=SetMsgSource:) NSString *msgSource; // @synthesize msgSource;
@property(readonly, nonatomic) BOOL hasMsgSource; // @synthesize hasMsgSource;
@property(nonatomic, setter=SetCreateTime:) unsigned int createTime; // @synthesize createTime;
@property(readonly, nonatomic) BOOL hasCreateTime; // @synthesize hasCreateTime;
@property(retain, nonatomic, setter=SetImgBuf:) SKBuiltinBuffer_t *imgBuf; // @synthesize imgBuf;
@property(readonly, nonatomic) BOOL hasImgBuf; // @synthesize hasImgBuf;
@property(nonatomic, setter=SetImgStatus:) unsigned int imgStatus; // @synthesize imgStatus;
@property(readonly, nonatomic) BOOL hasImgStatus; // @synthesize hasImgStatus;
@property(nonatomic, setter=SetStatus:) unsigned int status; // @synthesize status;
@property(readonly, nonatomic) BOOL hasStatus; // @synthesize hasStatus;
@property(retain, nonatomic, setter=SetContent:) SKBuiltinString_t *content; // @synthesize content;
@property(readonly, nonatomic) BOOL hasContent; // @synthesize hasContent;
@property(nonatomic, setter=SetMsgType:) int msgType; // @synthesize msgType;
@property(readonly, nonatomic) BOOL hasMsgType; // @synthesize hasMsgType;
@property(retain, nonatomic, setter=SetToUserName:) SKBuiltinString_t *toUserName; // @synthesize toUserName;
@property(readonly, nonatomic) BOOL hasToUserName; // @synthesize hasToUserName;
@property(retain, nonatomic, setter=SetFromUserName:) SKBuiltinString_t *fromUserName; // @synthesize fromUserName;
@property(readonly, nonatomic) BOOL hasFromUserName; // @synthesize hasFromUserName;
@property(nonatomic, setter=SetMsgId:) int msgId; // @synthesize msgId;
@property(readonly, nonatomic) BOOL hasMsgId; // @synthesize hasMsgId;
- (id)mergeFromCodedInputStream:(id)arg1;
- (int)serializedSize;
- (void)writeToCodedOutputStream:(id)arg1;
@end

@interface SendImageInfo : NSObject <NSCopying>
@property (nonatomic, assign) unsigned int m_uiOriginalHeight; // @synthesize m_uiOriginalHeight=_m_uiOriginalHeight;
@property (nonatomic, assign) unsigned int m_uiOriginalWidth; // @synthesize m_uiOriginalWidth=_m_uiOriginalWidth;
@property (nonatomic, assign) unsigned int m_uiThumbHeight; // @synthesize m_uiThumbHeight=_m_uiThumbHeight;
@property (nonatomic, assign) unsigned int m_uiThumbWidth; // @synthesize m_uiThumbWidth=_m_uiThumbWidth;
- (id)init;
@end


@interface MessageData : NSObject
- (id)initWithMsgType:(long long)arg1;
@property(retain, nonatomic) NSString *fromUsrName;
@property(retain, nonatomic) NSString *toUsrName;
@property(retain, nonatomic) NSString *msgContent;
@property(retain, nonatomic) NSString *msgPushContent;
@property(retain, nonatomic) NSString *msgRealChatUsr;
@property(retain, nonatomic) SendImageInfo *imageInfo;
@property(retain, nonatomic) id extendInfoWithMsgType;
@property(nonatomic) int messageType;
@property(nonatomic) int msgStatus;
@property(nonatomic) int msgCreateTime;
@property(nonatomic) int mesLocalID;
@property(nonatomic) long long mesSvrID;
@property(retain, nonatomic) NSString *msgVoiceText;
@property(copy, nonatomic) NSString *m_nsEmoticonMD5;
- (BOOL)isChatRoomMessage;
- (NSString *)groupChatSenderDisplayName;
- (id)getRealMessageContent;
- (id)getChatRoomUsrName;
- (BOOL)isSendFromSelf;
- (BOOL)isCustomEmojiMsg;
- (BOOL)isImgMsg;
- (BOOL)isVideoMsg;
- (BOOL)isVoiceMsg;
- (BOOL)canForward;
- (BOOL)IsPlayingSound;
- (id)summaryString:(BOOL)arg1;
- (BOOL)isEmojiAppMsg;
- (BOOL)isAppBrandMsg;
- (BOOL)IsUnPlayed;
- (void)SetPlayed;
@property(retain, nonatomic) NSString *m_nsTitle;
- (id)originalImageFilePath;
@property(retain, nonatomic) NSString *m_nsVideoPath;
@property (nonatomic, retain) NSString *m_nsVideoThumbPath;
@property(retain, nonatomic) NSString *m_nsFilePath;
@property(retain, nonatomic) NSString *m_nsAppMediaUrl;
@property(nonatomic) MessageData *m_refMessageData;
@property(nonatomic) unsigned int m_uiDownloadStatus;
- (void)SetPlayingSoundStatus:(BOOL)arg1;
@end



@interface XMLDictionaryParser : NSObject
+ (id)sharedInstance;
- (id)dictionaryWithString:(id)arg1;
- (id)dictionaryWithData:(id)arg1;
- (id)dictionaryWithParser:(id)arg1;
- (id)dictionaryWithFile:(id)arg1;
- (id)nameForNode:(id)arg1 inDictionary:(id)arg2;
@end


@interface MMCDNDownloadMgrExt : NSObject
- (void)cdnDownloadMgrDownloaded:(int)arg1 of:(int)arg2 withMessage:(id)arg3 type:(int)arg4 tryShow:(BOOL)arg5;
@end

@interface MMMessageCacheMgr : NSObject
- (void)originalImageWithMessage:(id)arg1 completion:(id)arg2;
- (void)originalImageWithPreviewMessage:(id)arg1 completion:(id)arg2;
- (void)downloadImageWithURLString:(id)arg1 message:(id)arg2 completion:(id)arg3;
- (void)downloadImageWithURLString:(id)arg1 thumbPath:(id)arg2 message:(id)arg3 completion:(id)arg4;
- (void)startDownloadImageWithMessage:(id)arg1 completion:(id)arg2;
@end

@interface MMCDNDownloadMgr : NSObject
- (BOOL)StopHttpsDownloadTask:(id)arg1;
- (BOOL)StartHttpsDownloadTask:(id)arg1 withUrl:(id)arg2 withSavePath:(id)arg3 withIPList:(id)arg4 withIsGzip:(BOOL)arg5 withFileType:(int)arg6;
- (void)OnCdnDownloadFinished:(id)arg1;
- (void)OnCdnDownloadProgress:(id)arg1;
- (id)fileCDNDownloadParaWithFavItemData:(id)arg1 destinationPath:(id)arg2 type:(int)arg3;
- (id)imageCDNDownloadParaWithFavItemData:(id)arg1;
- (id)thumbnailCDNDownloadParaWithFavItemData:(id)arg1;
- (id)videoCDNDownloadParaWithMessage:(id)arg1;
- (id)thumbnailCDNDownloadParaWithMessage:(id)arg1;
- (id)fileCDNDownloadParaWithMessage:(id)arg1 destinationPath:(id)arg2;
- (id)AppMsgImageCDNDownloadParaWithMessage:(id)arg1;
- (BOOL)startDownloadHeadAvatarImage:(id)arg1;
- (id)downloadCDNFileWithChatName:(id)arg1 mesLocalID:(unsigned int)arg2 recordMsgData:(id)arg3 type:(int)arg4 isThumbnail:(BOOL)arg5;
- (double)downloadProgressOfFaviItemData:(id)arg1;
- (void)startFavDownloadQueue;
- (id)downloadCDNFileWithFavItemData:(id)arg1 destinationPath:(id)arg2 type:(int)arg3;
- (id)downloadCDNFileWithFavItemData:(id)arg1 type:(int)arg2;
- (BOOL)messageIsInDownloadingList:(id)arg1;
- (void)cancelDownloadWithMessage:(id)arg1 type:(int)arg2;
- (BOOL)downloadCDNFileWithMessage:(id)arg1 type:(int)arg2 destinationPath:(id)arg3 signature:(id)arg4 fakeAeskey:(id)arg5 fakeSignature:(id)arg6;
- (BOOL)downloadCDNFileWithMessage:(id)arg1 type:(int)arg2 signature:(id)arg3 fakeAeskey:(id)arg4 fakeSignature:(id)arg5;
- (id)imageTmpPathWithMessage:(id)arg1;
- (id)imagePathWithMessage:(id)arg1;
- (BOOL)downloadImageWithMessage:(id)arg1 disableHevc:(BOOL)arg2;
- (BOOL)downloadImageWithMessage:(id)arg1;
- (void)destroy;
- (void)onServiceClearData;
- (void)onServiceInit;
- (void)dealloc;
- (id)init;
@end

@interface EmoticonMgr : NSObject
- (id)getEmoticonDescWithMD5:(id)arg1;
- (id)getEmotionThumbWithPackageID:(id)arg1;
- (id)getEmotionThumbWithMD5:(id)arg1;
- (id)getEmotionImgWithMD5:(id)arg1;
- (id)getEmotionDataWithMD5:(id)arg1;
@end

@interface CUtility : NSObject
+ (BOOL)HasWechatInstance;
+ (BOOL)FFSvrChatInfoMsgWithImgZZ;
+ (unsigned long long)getFreeDiskSpace;
+ (void)ReloadSessionForMsgSync;
+ (id)GetCurrentUserName;
@end
