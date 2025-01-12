#ifndef HTTP_FETCH_H
#define HTTP_FETCH_H

//----------------------------------------------------------------------------
//  Internal http fetch process used by the external functions defined in HTTP.h
//-----------------------------------------------------

class HTTPDownloadDetails
{
public:
	HTTPDownloadDetails()
	{
		fnResponseCallback = NULL;
		acLocalFilename[0] = 0;
		pcFullURL = NULL;
		pcPostFields = NULL;
		vpCBParam = 0;
		nState = 0;
		nBytesReceived = 0;
		nTotalBytes = 0;
		bCancelRequested = FALSE;
		nPartialDownloadStart = 0;
		nPartialDownloadEnd = 0;
		bIgnoreCache = FALSE;
		nResponseCode = 0;
		nPostBodyLen = 0;
		nCustomTimeout = 0;
	}

	HTTPResponseHandler				fnResponseCallback;
//	HTTPDownloadUpdateCallback		fnUpdateCallback;

	char		acLocalFilename[256];
	char*		pcFullURL;
	char*		pcPostFields;
	int			nPostBodyLen;
	void* 		vpCBParam;
	int			nState;

	int			nBytesReceived;
	int			nTotalBytes;
	BOOL		bCancelRequested;

	int			nPartialDownloadStart;
	int			nPartialDownloadEnd;
	BOOL		bIgnoreCache;
	int			nResponseCode;

	BYTE*		pbResponseBuffer;
	int			nResponseBufferSize;
	int			nCustomTimeout;
	void*		pLocalFile;
};

extern void		HTTPFetchGlobalInit( void );

extern void 	HTTPFetchSystemInit( void );

extern int		HTTPPerformFetch( char *acFullURL, HTTPDownloadDetails* pxDetails );

extern void		HTTPFetchSystemShutdown( void );

extern void		HTTPFetchGlobalShutdown( void );

extern BOOL		HTTPThreadShutdownRequested( void );


#endif
