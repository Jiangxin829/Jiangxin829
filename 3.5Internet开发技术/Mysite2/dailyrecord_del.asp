<!DOCTYPE html>
<html style="height: 100%;">
<head>
	<meta http-equiv="Content-Language" content="zh-cn">
	<meta http-equiv="Content-Type" content="text/html; charset=gb2312">
	<!--#include file="conn_head.asp"-->
	<link href="\css\global.css" rel="stylesheet">
	<title>删除日志</title>
</head>
<body>
<%
id=request("id")
dim ors
set ors=server.CreateObject("ADODB.recordset")
sql="delete * from dailyrecord where id="&id&""
ors.open sql,oConn,1,3
if err then
   response.Write("ERROR")
else
   response.Redirect("My_dailyrecord.asp")
end if
%>
</body>
</html>