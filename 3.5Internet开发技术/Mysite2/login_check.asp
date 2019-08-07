<!DOCTYPE html>
<html style="height: 100%;">
<head>
	<meta http-equiv="Content-Language" content="zh-cn">
	<meta http-equiv="Content-Type" content="text/html; charset=gb2312">
	<title>Log In ...</title>
	<!--#include file="conn_head.asp"-->
</head>
<body>
<%
	dim sql
	dim rs
	username_=request.Form("username")
	password_=request.Form("password")
	sql="select * from [user] where EmailAddress='"&username_&"' and Password='"&password_&"'"
	set rs=Server.CreateObject("ADODB.RecordSet")
	rs.Open sql,oConn,1,1
	if not rs.eof then
	   session("member")=username_
	   session("password")=password_
	   response.Redirect("index.asp?username="&username_&"")
	else
	   response.Write("<script language=javascript>alert('请检查账户或密码！');history.back();</script>")
	end if
	rs.close()
	set rs=nothing
	oConn.close()
	set oConn=nothing
	if err then
	   response.Write("ERROR")
	end if
%>
</body>
</html>