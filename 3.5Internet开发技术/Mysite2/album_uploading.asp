<!DOCTYPE html>
<html style="height: 100%;">
<head>
	<meta http-equiv="Content-Language" content="zh-cn">
	<meta http-equiv="Content-Type" content="text/html; charset=gb2312">
	<title>上传封面中..</title>
	<!--#include file="upload_class.inc"-->
	<link href="\css\global.css" rel="stylesheet">
</head>
<body style="font-size:12px">
<%
 Dim Upload,path
'===============================================================================
 set Upload=new AnUpLoad				 				'创建类实例        			'设置单个文件最大上传限制,按字节计；默认为不限制							
 Upload.openProcesser=false								'禁止进度条功能，如果启用，需配合客户端程序
 Upload.GetData()										'获取并保存数据,必须调用本方法
'===============================================================================
 if Upload.ErrorID>0 then	
    response.Write("出现错误")							'判断错误号,如果myupload.Err<=0表示正常
 	response.write Upload.Description 					'如果出现错误,获取错误描述
 else
 	if Upload.files(-1).count>0 then 					'这里判断你是否选择了文件
    		path=server.mappath("images/album_ground") 				'文件保存路径(这里是files文件夹)
    				
			dim dbpath,oConn,sConn,album_url
            dbpath="database\datasource.mdb"
            sConn="provider=Microsoft.Jet.OLEDB.4.0;Data Source="&server.mappath(dbpath)
            set oConn=Server.CreateObject("ADODB.Connection")
            oConn.Open sConn
			album_url="images/album_ground/"&session("name")
			set ors=server.CreateObject("ADODB.recordset")
			ors.open "select * from album where album_name<>"" and album_url="" order by id desc",oConn,1,3
			ors.update()
			ors("album_url")=album_url
			ors.update()
			if err then
			   response.Write("ACCESS ERROR")
			end if
			ors.close
			set ors=nothing
			oConn.close
			set oConn=nothing
			
    else
		response.Write "您没有上传任何文件！"
 	end if
 end if
 set Upload=nothing 
 if not err then
    response.Redirect("My_album.asp")
 end if                  '销毁类实例
%>
</body>
</html>