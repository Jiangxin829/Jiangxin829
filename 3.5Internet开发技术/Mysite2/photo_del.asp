<!DOCTYPE html>
<html style="height: 100%;">
<head>
	<meta http-equiv="Content-Language" content="zh-cn">
	<meta http-equiv="Content-Type" content="text/html; charset=gb2312">
	<!--#include file="conn_head.asp"-->
	<title>删除照片</title>
</head>

<body>
	<%
	id=request("id")
	dim ors
	set ors=server.CreateObject("ADODB.recordset")
	sql="delete * from photo where id="&id&""
	ors.open sql,oConn,1,3
	response.Redirect("album_content.asp?id="&session("now_album_id")&"")
	%>
</body>
</html>
