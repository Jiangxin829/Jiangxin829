<!DOCTYPE html>
<html style="height: 100%;">
<head>
	<meta http-equiv="Content-Language" content="zh-cn">
	<meta http-equiv="Content-Type" content="text/html; charset=gb2312">
	<title>创建新相册中..</title>
	<!--#include file="conn_head.asp"-->
	<link href="\css\global.css" rel="stylesheet">
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
							<th height="500" align="center" valign="top" scope="row" > 
							  <div align="center" width="600" height="700">
								<table style="font-size:17px" width="590pxpx" border="0" bordercolor="#000000" cellpadding="5" cellspacing="15"  >
								<tr>
								<td align="center"  colspan="2"><hr color="#dcdcdc" width="100%" />
								<p style="font-size:17px; font-weight:bold;" align="left">你的位置:</p>
								<p align="left"  style="font-size:17px; font-weight:bold;">
								<a href="My_album.asp" style="text-decoration:none; font-size:17px;"><b>相册列表</b></a>>>
								<a href="album_create.asp" style="text-decoration:none; font-size:17px;"><b>创建相册</b></a>>>上传封面
								</p>
								</td>
								</tr>	
								<tr>
								<td align="center"  colspan="2">
									<%
									album_name=request.Form("album_name")
									establish_time=request.Form("establish_time")
									dim ors
									set ors=server.CreateObject("ADODB.recordset")
									sql="select * from album"
									ors.open sql,oConn,1,3
									ors.addnew()
									ors("album_name")=album_name
									ors("establish_time")=establish_time
									ors.update()
									if err then
									  response.Write("请修改时间格式")
									else
									  ors.close()
									  set ors=nothing
									  response.Redirect("album_upload.asp")
									end if
									%>								
								</td>
								</tr>	
							</th>
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
<body>

</body>
</html>
