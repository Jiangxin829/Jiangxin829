<!DOCTYPE html>
<html style="height: 100%;">
<head>
	<meta http-equiv="Content-Language" content="zh-cn">
	<meta http-equiv="Content-Type" content="text/html; charset=gb2312">
	<title>�ϴ�������..</title>
	<!--#include file="upload_class.inc"-->
	<link href="\css\global.css" rel="stylesheet">
</head>
<body style="font-size:12px">
<%
 Dim Upload,path
'===============================================================================
 set Upload=new AnUpLoad				 				'������ʵ��        			'���õ����ļ�����ϴ�����,���ֽڼƣ�Ĭ��Ϊ������							
 Upload.openProcesser=false								'��ֹ���������ܣ�������ã�����Ͽͻ��˳���
 Upload.GetData()										'��ȡ����������,������ñ�����
'===============================================================================
 if Upload.ErrorID>0 then	
    response.Write("���ִ���")							'�жϴ����,���myupload.Err<=0��ʾ����
 	response.write Upload.Description 					'������ִ���,��ȡ��������
 else
 	if Upload.files(-1).count>0 then 					'�����ж����Ƿ�ѡ�����ļ�
    		path=server.mappath("images/album_ground") 				'�ļ�����·��(������files�ļ���)
    				
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
		response.Write "��û���ϴ��κ��ļ���"
 	end if
 end if
 set Upload=nothing 
 if not err then
    response.Redirect("My_album.asp")
 end if                  '������ʵ��
%>
</body>
</html>