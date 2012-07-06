#include <iostream>
#include "PlayerPlaylist.hpp"

PlayerPlaylist::PlayerPlaylist() : m_VBox(Gtk::ORIENTATION_VERTICAL) {

  set_size_request(400, 200);

  add(m_VBox);

  //Add the TreeView, inside a ScrolledWindow, with the button underneath:
  m_ScrolledWindow.add(m_TreeView);

  //Only show the scrollbars when they are necessary:
  m_ScrolledWindow.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);

  m_VBox.pack_start(m_ScrolledWindow);

  //Create the Tree model:
  m_refTreeModel = Gtk::ListStore::create(m_Columns);
  m_TreeView.set_model(m_refTreeModel);

  //Add the TreeView's view columns:
  //This number will be shown with the default numeric formatting.
  m_TreeView.append_column("N", m_Columns.m_col_id);
  m_TreeView.append_column("Artist", m_Columns.m_col_artist);
  m_TreeView.append_column("Album", m_Columns.m_col_album);
  m_TreeView.append_column("Title", m_Columns.m_col_title);

}

void PlayerPlaylist::addLine(int id, char * t, char * ar, char * al) {

  Gtk::TreeModel::Row row = *(m_refTreeModel->append());
  row[m_Columns.m_col_id] = id;
  if (!ar)
    row[m_Columns.m_col_artist] = "Inconnu";
  else
    row[m_Columns.m_col_artist] = ar;
  if (!al)
    row[m_Columns.m_col_album] = "Inconnu";
  else
    row[m_Columns.m_col_album] = al;
  if (!t)
    row[m_Columns.m_col_title] = "Inconnu";
  else
    row[m_Columns.m_col_title] = t;

  
}

void PlayerPlaylist::select(int id) {

  std::stringstream ss;
  ss << id;

  Gtk::TreePath tp(ss.str());

  //Gtk::TreeViewColumn *tvc;
  //  m_TreeView.get_cursor(tp,tvc);
  std::cout<<tp.to_string()<<std::endl;
  //tp.next();
  m_TreeView.set_cursor(tp);
}


PlayerPlaylist::~PlayerPlaylist() {
}
