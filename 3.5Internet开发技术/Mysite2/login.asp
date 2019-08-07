
<!DOCTYPE html>
<html style="height: 100%;">
<head>
	<meta http-equiv="Content-Language" content="zh-cn">
	<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
	<title>Log In</title>
	<link href="\css\global.css" rel="stylesheet">
	<script language="javascript">
	function check()
	{
		if(document.getElementById("username").value=="")
		{
			alert("请填写Email Address一栏");
			return false;
		}
		else
		{
			if(document.getElementById("password").value=="")
			{
				alert("请填写Password一栏");
				return false;
			}
			else
			{
				return true;
			}
		}
	}
	</script>
</head>

<body class="login_body">
	<div class="web_fluid_container">
		<div class="web_vcenter">
			<div id="login_container">
				<div id="login_module">
					<a href="http://192.168.174.1:8088/" class="login-element"></a>
					<form action="login_check.asp" method="post" name="form1" id="form1" onsubmit="return check();">
					<input type="hidden" name="action" value="normal">
					<input type="hidden" name="login_type" value="normal">
					<div class="login-email">
						<input name="username" type="text" class="flexwidth100" placeholder="Email Address" />
					</div>
					<hr>
					<div class="login-password">
						<input name="password" type="password" class="flexwidth100" placeholder="Password" />
					</div>
					<hr>
					<div style="clear: both"></div>
					<input type="submit" value="Login" />
					<hr>
					Help, I <a href="back1.asp">forgot my password</a>.
					</form>
				</div>
			</div>
		</div>
	</div>
	
</body>
</html>

