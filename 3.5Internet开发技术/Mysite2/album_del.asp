<!DOCTYPE html>
<html style="height: 100%;">
<head>
	<meta http-equiv="Content-Language" content="zh-cn">
	<meta http-equiv="Content-Type" content="text/html; charset=gb2312">
	<!--#include file="conn_head.asp"-->
	<title>删除相册</title>
</head>
<body>
	<%
	id=request("id")
	dim ors
	set ors=server.CreateObject("ADODB.recordset")
	sql="delete * from album where id="&id&""
	ors.open sql,oConn,1,3
	ors.close()
	sql="delete * from photo where album_id="&id&""
	ors.open sql,oConn,1,3
	if not err then
	response.Redirect("My_album.asp")
	else
	response.Write("ERROR")
	end if
	%>
</body>
</html>