<!DOCTYPE html>
<html style="height: 100%;">
<head>
	<meta http-equiv="Content-Language" content="zh-cn">
	<meta http-equiv="Content-Type" content="text/html; charset=gb2312">
	<title>����б�</title>
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
								<a href="self_introduction.asp">��������</a>
							</div>
							</th>
						  </tr>
						  <tr>
							<th scope="row">@</th>
							<td><div align="left">
								<a href="My_album.asp">�ҵ����</a>
							</div></td>
						  </tr>
						  <tr>
							<th scope="row">@</th>
							<td><div align="left">
								<a href="My_dailyrecord.asp">�ҵ���־</a>
							</div></td>
						  </tr>
						  <tr>
							<th scope="row">@</th>
							<td><div align="left">
								<a href="/back1.asp">���ڸ���</a>
							</div></td>
						  </tr>
						</table>
						</th>
						<td width="700" valign="top"><table width="100%" height="800" border="0">
						  <tr>
							<th height="20" align="center" bgcolor="#f8f8ff" scope="col">
							<div align="center">
								<h3>�ҵ����</h3>
							</div></th>
						  </tr>
						  <tr>
							<th height="500" align="center" bgcolor="#f5fffa" valign="top" scope="row" > 
							  <div align="center" width="600" height="700">
								<table style="font-size:12px" width="590pxpx" border="0" bordercolor="#000000" cellpadding="5" cellspacing="15"  >
								<tr>
								<td align="center"  colspan="2"><hr color="#dcdcdc" width="100%" />
								</td>
								</tr>
								<%
								dim ors
								set ors=server.CreateObject("ADODB.recordset")
								sql="select * from album order by id desc"
								ors.open sql,oConn,1,1
								if not ors.eof then
								for i=1 to ors.recordcount
								%>
								<div align="center">
									<tr>
									<td rowspan="5" width="350px" align="center"><a href="album_content.asp?id=<%=ors("id")%>" ><img src="<%=ors("album_url")%>"  width="250px" height="200px" style="border:4px outset #ffff00" /></a>
									</td>
									</tr>
									<tr>
									<td align="left"  height="20px"><b>�������:<%=ors("album_name")%></b></td>
									</tr>
									<tr>
									<td align="left"  height="20px"><b>����ʱ��:<%=ors("establish_time")%></b></td>
									</tr>
									<tr>
									<td align="left"  height="20px" ><b><a href="photo_upload.asp?id=<%=ors("id")%>" style="text-decoration:none;">�ϴ���Ƭ</a>|
									<a href="album_del.asp?id=<%=ors("id")%>" style="text-decoration:none;">ɾ�����</a></b></td>
									</tr>
									<tr>
									<td align="left"  height="20px" ><b><a href="album_content.asp?id=<%=ors("id")%>" style="text-decoration:none;">������</a></b></td>
									</tr>
									<tr>
									<td height="10px" ><hr color="#d3d3d3" align="center" width="160%" /></td>
									</tr>
								</div>
								<%
								ors.movenext
								next
								end if
								%>
								
								</table>
							  </div>
							</th>
							<tr>
							<td height="100px" width="350px" align="center" bgcolor="#f8f8ff" scope="row"><a href="album_create.asp" style="text-decoration:none; font-size:15px;"><b>���������</b></a></td>							
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