' @author: skitsanos
' @build: Thu, 25 Jul 2002 18:45:56 -0000

' Using new arahnoWare Web.Objects tips

' Declaring Application type
$APPTYPE CGI

' Including Web.Objects
$INCLUDE "OBJ_HTTP.INC"
' Including Rapid-Q Constants
$INCLUDE "RAPIDQ.INC"

' This line will break execution if file requested not by browser
IF REQUEST.HTTP_USER_AGENT ="" THEN END

' If requested by browser, generate response
' with a proper status code.
' for IE you can generate always "200 OK" status, because IE
' don't see any difference in response codes.
RESPONSE.STATUS "200 OK"

' Declaring content type
RESPONSE.CONTENTTYPE "text/html"
' Also you can add/declare DocType when you using XML, WML and etc...

' And now send this generated header.
' Without sending header u will get CGI Error
RESPONSE.SENDHEADER

DIM USERNAME AS STRING
DIM PASSWORD AS STRING
' Here we are looking for some values posted from browser
	USERNAME = HTTP.GETVALUE("username")
	PASSWORD = HTTP.GETVALUE("password")

	DIM BUF AS STRING
' Now loading some page, which contains "keywords"
' We are using keyword on page for automate content management process
' In this case we will nee to design only one page, which will be
' as basement for whole web site.
	BUF = FSO.FILETOBUFFER("templates/t_index.htm")
' So, page loaded to buffer and now we processing keywords
	BUF = REPLACESUBSTR$(BUF,"{@footer}","Copyright (c) 2002")
' and now checking for user settings
' if we have a "guest", show him a login form, which also prepared
' as "template"
	IF USERNAME="" AND PASSWORD ="" THEN
		DIM LOGINFORMCONTENT AS STRING
		LOGINFORMCONTENT = FSO.FILETOBUFFER("templates/t_loginform.htm")
		BUF = REPLACESUBSTR$(BUF,"{@header}","Please enter your account details:")
		BUF = REPLACESUBSTR$(BUF,"{@menucontent}",LoginFormContent)
	END IF
	
' Now we are displaying generated HTML content to user and he will
' see it as normal web page.
	RESPONSE.WRITE BUF
	
' Here is the small example of using "Response" object
	RESPONSE.WRITE "<HR NOSHADE SIZE=1 COLOR=RED>"
	RESPONSE.WRITE "REFERER: " & REQUEST.HTTP_REFERER & "<BR>"
	RESPONSE.WRITE "PATH_TRANSLATED:" & REQUEST.PATH_TRANSLATED & "<BR>"
	RESPONSE.WRITE "REQUEST_METHOD: " & REQUEST.REQUEST_METHOD & "<BR>"
	RESPONSE.WRITE "QUERY_STRING: " & REQUEST.QUERY_STRING & "<BR>"
	RESPONSE.WRITE "DECODED STRING: " & HTTP.HTMLDECODE(REQUEST.QUERY_STRING) & "<BR>"
