<!DOCTYPE html>
<html style="height: 100%;">
<head>
	<meta http-equiv="Content-Language" content="zh-cn">
	<meta http-equiv="Content-Type" content="text/html; charset=gb2312">
	<title>���������</title>
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
								<p style="font-size:17px; font-weight:bold;" align="left">���λ��:</p>
								<p align="left"  style="font-size:17px; font-weight:bold;">
								<a href="My_album.asp" style="text-decoration:none; font-size:17px;"><b>����б�</b></a>>>�������
								</p>
								</td>
								</tr>	
								<tr>
								<td align="center"  colspan="2">
									<form action="album_creating.asp" method="post" name="form1" id="form1">
									<div style="login-email">
										<input type="text" name="album_name" class="flexwidth100" id="album_name" placeholder="�������"/>
										<input name="establish_time" type="text" class="flexwidth100" id="establish_time" placeholder="����ʱ�� ��'2019/4/25'" />
									</div>
									<hr color="#dcdcdc">
									<div style="clear: both"></div>
										<input type="submit" value="�ύ" />
										<input type="reset" value="����" />							
									</form>
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