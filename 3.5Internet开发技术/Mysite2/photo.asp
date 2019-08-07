<!DOCTYPE html>
<html style="height: 100%;">
<head>
	<meta http-equiv="Content-Language" content="zh-cn">
	<meta http-equiv="Content-Type" content="text/html; charset=gb2312">
	<!--#include file="conn_head.asp"-->
	<link href="\css\global.css" rel="stylesheet">
	<title>我的照片</title>
	<style type="text/css">
	#all{width:580px;
		 border:0;
		 background:url(images/000.jpg);
		 margin:5px;}
	#chip{width:116px;
		  border:0;
		  margin:13px;
		  float:left;}
	</style>
</head>
<body class="album_body">
	<div class="web_fluid_container">
		<div class="web_vcenter">
			<div id="album_container">
				<div id="album_module" >
					  	<%
						now_photo_id=request("id")
						dim ors
						set ors=server.CreateObject("ADODB.recordset")
						sql="select * from photo where id="&now_photo_id&""
						ors.open sql,oConn,1,1
						if not ors.eof then
							for i=1 to ors.recordcount
						%>
						<center>
						<div id="all">
						<p style="font-size:20px; font-weight:bold;" align="left">你的位置:</p>
						<p align="left"  style="font-size:20px; font-weight:bold;">
						<a href="My_album.asp" style="text-decoration:none; font-size:20px;"><b>相册列表</b></a>>>
						<a href="album_content.asp?id=<%=ors("album_id")%>" style="text-decoration:none; font-size:20px;">相册详情</a>>>查看照片
						</p>
						<hr color="#000000" align="center" width="86%" />
						<img src="<%=ors("photo_url")%>" border="1" width="500px" height="400px" border="3px"/>
						<br />
						<br />
						<a href="photo_del.asp?id=<%=ors("id")%>" style="font-size:20px; font-weight:bold; text-decoration:none">删除照片</a>&nbsp &nbsp  &nbsp
						<a href="album_content.asp?id=<%=ors("album_id")%>" style="text-decoration:none; font-size:20px; font-weight:bold; ">返  回</a>
						<%
						ors.movenext
						next
						end if
						%>
						</div>
						</center>
				</div>
			</div>
		</div>
	</div>
</body>
</html>