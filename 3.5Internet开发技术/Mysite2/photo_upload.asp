<!DOCTYPE html>
<html style="height: 100%;">
<head>
	<meta http-equiv="Content-Language" content="zh-cn">
	<meta http-equiv="Content-Type" content="text/html; charset=gb2312">
	<!--#include file="conn_head.asp"-->
	<link href="\css\global.css" rel="stylesheet">
	<title>�ϴ���Ƭ</title>
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
						<td width="700" valign="top"><table width="100%" height="500" border="0">
						  <tr>
							<th height="20" align="center" bgcolor="#f8f8ff" scope="col">
							<div align="center">
								<h3>�ҵ����</h3>
							</div></th>
						  </tr>
						  <tr>
							<th height="700" align="center" bgcolor="#f5fffa" valign="top" scope="row" > 
							  <div align="center" width="700" height="700">
								<table style="font-size:12px" width="590pxpx" border="0" bordercolor="#000000" cellpadding="5" cellspacing="5"  >
								<tr>
								<td align="center"  colspan="2"><hr color="#000000" width="100%" />
								<p style="font-size:17px; font-weight:bold;" align="left">���λ��:</p>
								<p align="left"  style="font-size:17px; font-weight:bold;">
								<a href="My_album.asp" style="text-decoration:none; font-size:17px;"><b>����б�</b></a>>>�ϴ���Ƭ
								</p>
								</td>
								</tr>

								<div>
								<tr>
								<td rowspan="5" width="500px" height="200px" align="center">
								<%
								id=request("id")
								session("id_")=id
								%>
								<p style="font-size:20px; font-weight:bold;">��ѡ��Ҫ�ϴ�����������Ƭ</p>
								<form name="upload" method="post" action="pho_uploading.asp" enctype="multipart/form-data">
								<input type="file" name="file1" />
								<input class="iButton" type="submit" value="�� ��" />
								</form>
								</td>
								</tr>							
								</div>
						
							  </div>
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
