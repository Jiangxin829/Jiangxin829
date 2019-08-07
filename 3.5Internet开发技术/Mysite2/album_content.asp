<!DOCTYPE html>
<html style="height: 100%;">
<head>
	<meta http-equiv="Content-Language" content="zh-cn">
	<meta http-equiv="Content-Type" content="text/html; charset=gb2312">
	<!--#include file="conn_head.asp"-->
	<link href="\css\global.css" rel="stylesheet">
	<title>相片列表</title>
</head>
<body class="album_body">
	<div class="web_fluid_container">
		<div class="web_vcenter">
			<div id="album_container">
				<div id="album_module">
					<table width="900" height="800" border="1" align="center" >
					  <tr>
						<th bgcolor="#fffafa" width="160" height="800" valign="top" scope="row"><table width="100%" height="800" border="0">
						  <tr>
							<th width="36%" scope="col">@</th>
							<th width="64%" scope="col" style="font-weight:normal ;">
							<div align="left">
								<a href="self_introduction.asp">自我评价</a>
							</div>
							</th>
						  </tr>
						  <tr>
							<th scope="row">@</th>
							<td><div align="left">
								<a href="My_album.asp">我的相册</a>
							</div></td>
						  </tr>
						  <tr>
							<th scope="row">@</th>
							<td><div align="left">
								<a href="My_dailyrecord.asp">我的日志</a>
							</div></td>
						  </tr>
						  <tr>
							<th scope="row">@</th>
							<td><div align="left">
								<a href="/back1.asp">关于更多</a>
							</div></td>
						  </tr>
						</table>
						</th>
						<td width="700" valign="top"><table width="100%" height="800" border="0">
						  <tr>
							<th height="20" align="center" bgcolor="#f8f8ff" scope="col">
							<div align="center">
								<h3>我的相册</h3>
							</div></th>
						  </tr>
						  <tr>
							<th height="500" align="center" bgcolor="#f5fffa" valign="top" scope="row" > 
							  <div align="center" width="600" height="700">
								<table style="font-size:12px" width="590pxpx" border="0" bordercolor="#000000" cellpadding="5" cellspacing="15"  >
								<tr>
								<td align="center"  colspan="2"><hr color="#dcdcdc" width="100%" />
								<p style="font-size:17px; font-weight:bold;" align="left">你的位置:</p>
								<p align="left"  style="font-size:17px; font-weight:bold;">
								<a href="My_album.asp" style="text-decoration:none; font-size:17px;"><b>相册列表</b></a>>>相册详情
								</p>
								</td>
								</tr>
								<%
								now_album_id=request("id")
								session("now_album_id")=now_album_id
								dim ors
								set ors=server.CreateObject("ADODB.recordset")
								sql="select * from photo where album_id='"&now_album_id&"' order by id desc"
								ors.open sql,oConn,1,1
								if not ors.eof then
								for i=1 to ors.recordcount
								%>														
								<div align="center">
									<tr>
									<td rowspan="1" width="350px" align="center"><a href="photo.asp?id=<%=ors("id")%>" ><img src="<%=ors("photo_url")%>"  width="250px" height="200px" title="点击查看大图" style="border:4px outset #dcdcdc" /></a>
									</td>
									</tr>
									<tr>
									<td height="10px" ><hr color="#d3d3d3" align="center" width="50%" /></td>
									</tr>
								</div>
								<%
								ors.movenext
								next
								end if
								%>  								
							</th>
							<tr>
							<td height="50px" width="350px" align="center" scope="row"><a href="photo_upload.asp?id=<%=session("now_album_id")%>" style="text-decoration:none; font-size:15px;"><b>上传照片</b></a></td>							
							</tr>
						  </tr>
						</table></td>
					  </tr>
					</table>
				</div>
			</div>
		</div>
	</div>
</body>
</html>