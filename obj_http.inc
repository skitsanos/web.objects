' ----------------------------------------------
' Web.Objects Collection for CGI Development
' @author: skitsanos
' @version: 2.1
' July 27, 2002.
'
' ----------------------------------------------

TYPE QRESPONSE EXTENDS QObject
	SUB SEND (strDATA AS STRING)
		FOR T=1 TO LEN(strDATA)
			PRINT MID$(strDATA,T,1);
		NEXT
	END SUB
	
	SUB STATUS (httpStatusCode AS STRING)
		PRINT "HTTP/1.1 " & httpStatusCode
		PRINT "Status: " & httpStatusCode
	END SUB
	
	SUB CONTENTTYPE (httpContentType AS STRING)
		PRINT "Content-Type: " & httpContentType
	END SUB

	SUB DOCTYPE (httpDocType AS STRING)
		PRINT httpDocType
	END SUB

	SUB CHARSET (httpCharSet AS STRING)
		PRINT httpCharSet
	END SUB

	SUB REDIRECT(httpRedirectURL AS STRING)
		'Not implemented yet
	END SUB

	SUB SENDHEADER()
		PRINT
	END SUB
END TYPE

TYPE QREQUEST EXTENDS QOBJECT
	FUNCTION QUERY_STRING () AS STRING
		IF ENVIRON$("REQUEST_METHOD") = "GET" THEN
			RESULT = ENVIRON$("QUERY_STRING")
		ELSE
			DIM STDINLEN AS INTEGER
			STDINLEN = VAL(ENVIRON$("CONTENT_LENGTH"))
			RESULT = GET$(STDINLEN)
		END IF
	END FUNCTION

	FUNCTION PATH_INFO () AS STRING
		RESULT = ENVIRON$("PATH_INFO")
	END FUNCTION

	FUNCTION AUTH_TYPE () AS STRING
		RESULT = ENVIRON$("AUTH_TYPE")
	END FUNCTION

	FUNCTION CONTENT_LENGTH () AS STRING
		RESULT = ENVIRON$("CONTENT_LENGTH")
	END FUNCTION

	FUNCTION CONTENT_TYPE () AS STRING
		RESULT = ENVIRON$("CONTENT_TYPE")
	END FUNCTION

	FUNCTION GATEWAY_INTERFACE () AS STRING
		RESULT = ENVIRON$("GATEWAY_INTERFACE")
	END FUNCTION

	FUNCTION PATH_TRANSLATED () AS STRING
		RESULT = ENVIRON$("PATH_TRANSLATED")
	END FUNCTION

	FUNCTION HTTP_COOKIE () AS STRING
		RESULT = ENVIRON$("HTTP_COOKIE")
	END FUNCTION

	FUNCTION HTTP_ACCEPT () AS STRING
		RESULT = ENVIRON$("HTTP_ACCEPT")
	END FUNCTION

	FUNCTION HTTP_REFERER () AS STRING
		RESULT = ENVIRON$("HTTP_REFERER")
	END FUNCTION

	FUNCTION HTTP_USER_AGENT () AS STRING
		RESULT = ENVIRON$("HTTP_USER_AGENT")
	END FUNCTION

	FUNCTION REMOTE_ADDR () AS STRING
		RESULT = ENVIRON$("REMOTE_ADDR")
	END FUNCTION

	FUNCTION REMOTE_HOST () AS STRING
		RESULT = ENVIRON$("REMOTE_HOST")
	END FUNCTION

	FUNCTION REMOTE_IDENT () AS STRING
		RESULT = ENVIRON$("REMOTE_IDENT")
	END FUNCTION

	FUNCTION REMOTE_USER () AS STRING
		RESULT = ENVIRON$("REMOTE_USER")
	END FUNCTION

	FUNCTION REQUEST_METHOD () AS STRING
		RESULT = ENVIRON$("REQUEST_METHOD")
	END FUNCTION

	FUNCTION SCRIPT_NAME () AS STRING
		RESULT = ENVIRON$("SCRIPT_NAME")
	END FUNCTION

	FUNCTION SERVER_SOFTWARE () AS STRING
		RESULT = ENVIRON$("SERVER_SOFTWARE")
	END FUNCTION

	FUNCTION SERVER_NAME () AS STRING
		RESULT = ENVIRON$("SERVER_NAME")
	END FUNCTION

	FUNCTION SERVER_PORT () AS STRING
		RESULT = ENVIRON$("SERVER_PORT")
	END FUNCTION
	
	FUNCTION SERVER_PROTOCOL () AS STRING
		RESULT = ENVIRON$("SERVER_PROTOCOL")
	END FUNCTION
    
    FUNCTION ALLUSERSPROFILE () AS STRING
        RESULT = ENVIRON$("ALLUSERSPROFILE")
    END FUNCTION

    FUNCTION APPDATA () AS STRING
        RESULT = ENVIRON$("APPDATA")
    END FUNCTION

    FUNCTION CommonProgramFiles () AS STRING
        RESULT = ENVIRON$("CommonProgramFiles")
    END FUNCTION

    FUNCTION COMPUTERNAME () AS STRING
        RESULT = ENVIRON$("COMPUTERNAME")
    END FUNCTION

    FUNCTION ComSpec () AS STRING
        RESULT = ENVIRON$("ComSpec")
    END FUNCTION

    FUNCTION HOMEDRIVE () AS STRING
        RESULT = ENVIRON$("HOMEDRIVE")
    END FUNCTION

    FUNCTION HOMEPATH () AS STRING
        RESULT = ENVIRON$("HOMEPATH")
    END FUNCTION

    FUNCTION LOGONSERVER () AS STRING
        RESULT = ENVIRON$("LOGONSERVER")
    END FUNCTION

    FUNCTION NUMBER_OF_PROCESSORS () AS STRING
        RESULT = ENVIRON$("NUMBER_OF_PROCESSORS")
    END FUNCTION

    FUNCTION OS () AS STRING
        RESULT = ENVIRON$("OS")
    END FUNCTION

    FUNCTION Os2LibPath () AS STRING
        RESULT = ENVIRON$("Os2LibPath")
    END FUNCTION

    FUNCTION Path () AS STRING
        RESULT = ENVIRON$("Path")
    END FUNCTION

    FUNCTION PATHEXT () AS STRING
        RESULT = ENVIRON$("PATHEXT")
    END FUNCTION

    FUNCTION PROCESSOR_ARCHITECTURE () AS STRING
        RESULT = ENVIRONN$("PROCESSOR_ARCHITECTURE")
    END FUNCTION

    FUNCTION PROCESSOR_IDENTIFIER () AS STRING
        RESULT = ENVIRON$("PROCESSOR_IDENTIFIER")
    END FUNCTION

    FUNCTION PROCESSOR_LEVEL () AS STRING
        RESULT = ENVIRON$("PROCESSOR_LEVEL")
    END FUNCTION

    FUNCTION PROCESSOR_REVISION () AS STRING
        RESULT = ENVIRON$("PROCESSOR_REVISION")
    END FUNCTION

    FUNCTION ProgramFiles () AS STRING
        RESULT = ENVIRON$("ProgramFiles")
    END FUNCTION

    FUNCTION SystemDrive () AS STRING
        RESULT = ENVIRON$("SystemDrive")
    END FUNCTION

    FUNCTION SystemRoot () AS STRING
        RESULT = ENVIRON$("SystemRoot")
    END FUNCTION

    FUNCTION USERDOMAIN () AS STRING
        RESULT = ENVIRON$("USERDOMAIN")
    END FUNCTION

    FUNCTION USERNAME () AS STRING
        RESULT = ENVIRON$("USERNAME")
    END FUNCTION

    FUNCTION USERPROFILE () AS STRING
        RESULT = ENVIRON$("USERPROFILE")
    END FUNCTION

    FUNCTION WINDIR () AS STRING
        RESULT = ENVIRON$("windir")
    END FUNCTION
END TYPE

TYPE QHTTP EXTENDS QObject		
	FUNCTION GetValue(httpVariable As String) AS STRING
		DIM SplitTemp AS STRING
		DIM strDATA AS STRING
		DIM thisVARIABLE AS STRING
		DIM thisVALUE AS STRING

		IF ENVIRON$("REQUEST_METHOD") = "GET" THEN
			strDATA = ENVIRON$("QUERY_STRING")
		ELSE
			strDATA = GET$(VAL(ENVIRON$("CONTENT_LENGTH")))
		END IF

		FOR t=1 TO TALLY(strDATA,"&")+1
			SplitTEMP = FIELD$(strData,"&",t)
			thisVariable = FIELD$(SplitTEMP,"=",1)
			thisValue = FIELD$(SplitTEMP,"=",2)
			IF thisVariable = httpVariable then				
				RESULT=thisValue
				splitTEMP = ""
				thisValue = ""
				strDATA = ""
				EXIT FUNCTION
			END IF
		NEXT			
	END FUNCTION

	FUNCTION HTMLEncode (htmlStream as String) AS STRING
		htmlStream = REPLACESUBSTR$(htmlStream," ","%20")
		htmlStream = REPLACESUBSTR$(htmlStream,"+","%2B")
		htmlStream = REPLACESUBSTR$(htmlStream," ","+")
		htmlStream = REPLACESUBSTR$(htmlStream,"/","%2F")
		htmlStream = REPLACESUBSTR$(htmlStream,"\","%5C")
		htmlStream = REPLACESUBSTR$(htmlStream,"%","%25")
		htmlStream = REPLACESUBSTR$(htmlStream,"&","%26")
		htmlStream = REPLACESUBSTR$(htmlStream,"^","%5E")
		htmlStream = REPLACESUBSTR$(htmlStream,":","%3A")
		htmlStream = REPLACESUBSTR$(htmlStream,"<","%3C")
		htmlStream = REPLACESUBSTR$(htmlStream,">","%3E")
		htmlStream = REPLACESUBSTR$(htmlStream,"|","%7C")
		htmlStream = REPLACESUBSTR$(htmlStream,CHR$(10),"%A")
		htmlStream = REPLACESUBSTR$(htmlStream,CHR$(13),"%D")
		htmlStream = REPLACESUBSTR$(htmlStream,CHR$(27),"%1B")	
		RESULT = htmlStream
	END FUNCTION
	
	FUNCTION HTMLDecode (htmlStream as String) AS STRING
		htmlStream = REPLACESUBSTR$(htmlStream,"%20"," ")
		htmlStream = REPLACESUBSTR$(htmlStream,"%2B","+")
		htmlStream = REPLACESUBSTR$(htmlStream,"+"," ")
		htmlStream = REPLACESUBSTR$(htmlStream,"%2F","/")
		htmlStream = REPLACESUBSTR$(htmlStream,"%5C","\")
		htmlStream = REPLACESUBSTR$(htmlStream,"%25","%")
		htmlStream = REPLACESUBSTR$(htmlStream,"%26","&")
		htmlStream = REPLACESUBSTR$(htmlStream,"%5E","^")
		htmlStream = REPLACESUBSTR$(htmlStream,"%3A",":")
		htmlStream = REPLACESUBSTR$(htmlStream,"%3C","<")
		htmlStream = REPLACESUBSTR$(htmlStream,"%3E",">")
		htmlStream = REPLACESUBSTR$(htmlStream,"%7C","|")
		htmlStream = REPLACESUBSTR$(htmlStream,"%A",CHR$(10))
		htmlStream = REPLACESUBSTR$(htmlStream,"%D",CHR$(13))
		htmlStream = REPLACESUBSTR$(htmlStream,"%1B",CHR$(27))
		RESULT = htmlStream
	END FUNCTION
	
	FUNCTION MAPPATH(httpPath AS STRING) AS STRING		
		RESULT = 0
	END FUNCTION

    FUNCTION BASE64ENCODE(strSource AS STRING) AS STRING
        DIM BAS64_TABLE AS STRING        
        Dim strTempLine AS STRING

        BASE64_TABLE = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"
        
        fornextcycle = Len(strSource) - Len(strSource) Mod 3

        For j = 1 To fornextcycle Step 3          
            strTempLine = strTempLine + Mid$(BASE64_TABLE, (Asc(Mid$(strSource, j, 1)) \ 4) + 1, 1)           
            strTempLine = strTempLine + Mid$(BASE64_TABLE, ((Asc(Mid$(strSource, j, 1)) Mod 4) * 16 + Asc(Mid$(strSource, j + 1, 1)) \ 16) + 1, 1)
            strTempLine = strTempLine + Mid$(BASE64_TABLE, ((Asc(Mid$(strSource, j + 1, 1)) Mod 16) * 4 + Asc(Mid$(strSource, j + 2, 1)) \ 64) + 1, 1)
            strTempLine = strTempLine + Mid$(BASE64_TABLE, (Asc(Mid$(strSource, j + 2, 1)) Mod 64) + 1, 1)
        Next j

        If Not (Len(strSource) Mod 3) = 0 Then
            If (Len(strSource) Mod 3) = 2 Then
                strTempLine = strTempLine + Mid$(BASE64_TABLE, (Asc(Mid$(strSource, j, 1)) \ 4) + 1, 1)                
                strTempLine = strTempLine + Mid$(BASE64_TABLE, (Asc(Mid$(strSource, j, 1)) Mod 4) * 16 + Asc(Mid$(strSource, j + 1, 1)) \ 16 + 1, 1)               
                strTempLine = strTempLine + Mid$(BASE64_TABLE, (Asc(Mid$(strSource, j + 1, 1)) Mod 16) * 4 + 1, 1)
                strTempLine = strTempLine & "="
            ElseIf (Len(strSource) Mod 3) = 1 Then                
                strTempLine = strTempLine + Mid$(BASE64_TABLE, (Asc(Mid$(strSource, j, 1)) \ 4) + 1, 1)                
                strTempLine = strTempLine + Mid$(BASE64_TABLE, (Asc(Mid$(strSource, j, 1)) Mod 4) * 16 + 1, 1)                
                strTempLine = strTempLine & "=="                
            End If        
        End If 
      
        RESULT = strTempLine        
        END FUNCTION
        
        FUNCTION FETCHPAGE (URL AS STRING) AS STRING
        	DIM INETCONTROL AS QOLEOBJECT
        	DIM FETCHBUFFER AS STRING
        	FETCHBUFFER = ""
        	INETCONTROL.CREATEOBJECT("InetCtlsObjects.Inet")        	
        	FETCHBUFFER = INETCONTROL.OPENURL (URL,0)
        	PRINT FETCHBUFFER
        END FUNCTION
END TYPE

TYPE QFSO EXTENDS QOBJECT
	FUNCTION FILETOBUFFER (fsoFileName AS STRING) AS STRING
		DIM FILE AS QFILESTREAM
		DIM THISBUFFER AS STRING
		DIM MABYTE AS BYTE
        THISBUFFER = ""

		IF FILE.OPEN (fsoFileName, fmOpenRead) = FALSE THEN
			RESULT = ""
		ELSE
			WHILE FILE.EOF = FALSE	
				FILE.READ(MABYTE)				
				THISBUFFER = THISBUFFER + CHR$(MABYTE)
			WEND		
			FILE.CLOSE
			RESULT = THISBUFFER
		END IF
	END FUNCTION
END TYPE

Function sysFormItem AS STRING
	sysFormItem="BACKGROUND-COLOR: #ffffee; BORDER-LEFT: 0px; BORDER-TOP: 0px; FONT-FAMILY: Verdana, Tahoma, Helvetica; FONT-SIZE: 11px"
End Function

Function sys100FormItem AS STRING
	sys100FormItem="BACKGROUND-COLOR: #ffffee; BORDER-LEFT: 0px; BORDER-TOP: 0px; WIDTH: 100%; FONT-FAMILY: Verdana, Tahoma, Helvetica; FONT-SIZE: 11px"
End Function

Function sysButton AS STRING
	sysButton="BACKGROUND-COLOR: lightsteelblue; BORDER-BOTTOM-COLOR: #ffffff; BORDER-BOTTOM-WIDTH: 1px; BORDER-LEFT-COLOR: #ffffff; BORDER-LEFT-WIDTH: 1px; BORDER-RIGHT-COLOR: #ffffff; BORDER-RIGHT-WIDTH: 1px; BORDER-TOP-COLOR: #ffffff; BORDER-TOP-WIDTH: 1px; FONT-FAMILY: Verdana, Tahoma, Helvetica; FONT-SIZE: 10px"
End Function

Function sys100Button AS STRING
	sys100Button="BACKGROUND-COLOR: lightsteelblue; BORDER-BOTTOM-COLOR: #ffffff; BORDER-BOTTOM-WIDTH: 1px; BORDER-LEFT-COLOR: #ffffff; BORDER-LEFT-WIDTH: 1px; BORDER-RIGHT-COLOR: #ffffff; BORDER-RIGHT-WIDTH: 1px; BORDER-TOP-COLOR: #ffffff; BORDER-TOP-WIDTH: 1px; FONT-FAMILY: Verdana, Tahoma, Helvetica; FONT-SIZE: 10px; WIDTH: 100%"
End Function

DIM RESPONSE AS QRESPONSE
DIM REQUEST AS QREQUEST
DIM HTTP AS QHTTP
DIM FSO AS QFSO
