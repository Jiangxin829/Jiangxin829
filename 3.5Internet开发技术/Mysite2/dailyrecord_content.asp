<!DOCTYPE html>
<html style="height: 100%;">
<head>
	<meta http-equiv="Content-Language" content="zh-cn">
	<meta http-equiv="Content-Type" content="text/html; charset=gb2312">
	<!--#include file="conn_head.asp"-->
	<link href="\css\global.css" rel="stylesheet">
	<title>��־����</title>
</head>
<body class="dailyrecord_body">
	<div class="web_fluid_container">
		<div class="web_vcenter">
			<div id="dailyrecord_container">
				<div id="dailyrecord_module">
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
						<td width="700" valign="top">
						<table width="100%" height="800" border="0">
						  <tr>
							<th height="20" align="center" bgcolor="#f8f8ff" scope="col">
							<div align="center">
								<h3>�ҵ���־</h3>
							</div></th>
						  </tr>
						  <tr>
							<th height="500" align="center"   bgcolor="#f5fffa" valign="top" scope="row" > 
							  <div align="center" width="600" height="700">
								<table style="font-size:17px" width="590pxpx" border="0" bordercolor="#000000" cellpadding="5" cellspacing="5"  >
								<tr>
								<td align="center"  colspan="1"><hr color="#dcdcdc" width="100%" />
								
								<p align="left"  style="font-size:17px; font-weight:bold;">
								<a href="My_dailyrecord.asp" style="text-decoration:none; font-size:17px;"><b><<����</b></a>
								</p>
								<%
								id=request("id")
								dim ors
								set ors=server.CreateObject("ADODB.recordset")
								sql="select * from dailyrecord where id="&id&""
								ors.open sql,oConn,1,1
								%>
								<table style="font-size:17px" width="590pxpx" border="0" bordercolor="#000000" cellpadding="5" cellspacing="5" >
								<tr>
								<td align="center" height="20px" style="font-size:17px; font-weight:bold;" colspan="2"><%=ors("title")%></td>
								</tr>
								<tr>
								<td align="right" colspan="2"><b>������:<%=ors("writing_time")%></b></td>
								</tr>
								<tr>
								<td align="center" valign="top" height="" colspan="2"><%=ors("content")%></td>
								</tr>
								</table>
								</td>
								</tr>
								</table>
								</center>
																							
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