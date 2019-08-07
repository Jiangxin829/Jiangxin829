<!DOCTYPE html>
<html style="height: 100%;">
<head>
	<meta http-equiv="Content-Language" content="zh-cn">
	<meta http-equiv="Content-Type" content="text/html; charset=gb2312">
	<title>个人主页</title>
	<link href="\css\global.css" rel="stylesheet">
</head>
<body class="web_body">
	<h2>Hi, <%=Request.QueryString("username")%>！Welcome home!</h2>
	<div class="divcss5" style="position: absolute;left: 30px;top: 40px;width:150px; height:150px;background:url(/images/11.jpg) ;background-size: 150px; background-repeat: no-repeat; background-position:center;">
	<span>自我评价</span>
	<a href="self_introduction.asp" class="now">&nbsp;</a>
	</div>
	
	<div class="divcss5" style="position: absolute;left: 430px;top: 240px;width:150px; height:150px;background:url(/images/12.jpg) ;background-size: 150px; background-repeat: no-repeat; background-position:center;">
	<span>我的相册</span>
	<a href="My_album.asp" class="now">&nbsp;</a>
	</div>
	
	<div class="divcss5" style="position: absolute;left: 830px;top: 440px;width:150px; height:150px;background:url(/images/13.jpg) ;background-size: 150px; background-repeat: no-repeat; background-position:center;">
	<span>我的日志</span>
	<a href="My_dailyrecord.asp" class="now">&nbsp;</a>
	</div>
	
	<div class="divcss5" style="position: absolute;left: 1230px;top: 640px;width:150px; height:150px;background:url(/images/14.jpg) ;background-size: 150px; background-repeat: no-repeat; background-position:center;">
	<span>更多</span>
	<a href="back1.asp" class="now">&nbsp;</a>
	</div>

</body>
</html>
