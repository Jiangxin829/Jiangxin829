<%
	On Error Resume Next

	dim dbpath,oConn,sConn

	dbpath="database\datasource.mdb"
	sConn="provider=Microsoft.Jet.OLEDB.4.0;Data Source="&server.mappath(dbpath)

	set oConn=Server.CreateObject("ADODB.Connection")
	oConn.Open sConn

	if err then
	   response.write("�������ݿ����")
	end if
%>