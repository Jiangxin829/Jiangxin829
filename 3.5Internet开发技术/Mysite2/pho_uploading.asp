
<!DOCTYPE html>
<html style="height: 100%;">
<head>
	<meta http-equiv="Content-Language" content="zh-cn">
	<meta http-equiv="Content-Type" content="text/html; charset=gb2312">
	<!--#include file="upload_class.inc"-->
	<title>�ϴ���Ƭ��</title>
	<style type="text/css">
	TABLE {border:1px green solid;margin-top:5px;}
	TD{border-bottom:1px #dddddd solid;height:20px;padding:3px 0 0 5px;}
	.head{background-color:#eeeeee;}
	</style>
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
    		
			
			
			dim dbpath,oConn,sConn,imgurl
            dbpath="database\datasource.mdb"
            sConn="provider=Microsoft.Jet.OLEDB.4.0;Data Source="&server.mappath(dbpath)
            set oConn=Server.CreateObject("ADODB.Connection")
            oConn.Open sConn
			photo_url="images/album/"&session("name")
			set ors=server.CreateObject("ADODB.recordset")
			ors.open "select * from photo",oConn,1,3
			ors.addnew()
			ors("photo_url")=photo_url
			ors("album_id")=session("id_")
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
    response.Redirect("album_content.asp?id="&session("id_")&"")
 end if                  '������ʵ��
%>
</body>
</html>

