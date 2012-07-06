#ifndef PLAYERPLAYLIST_H
#define PLAYERPLAYLIST_H

#include <gtkmm.h>

class PlayerPlaylist : public Gtk::Frame
{
public:
  PlayerPlaylist();
  virtual ~PlayerPlaylist();

  void addLine(int, char *, char *, char *);
  void select(int);

protected:
  //Tree model columns:
  class ModelColumns : public Gtk::TreeModel::ColumnRecord
  {
  public:

    ModelColumns()
    { add(m_col_id); add(m_col_artist); add(m_col_album); add(m_col_title);}

    Gtk::TreeModelColumn<unsigned int> m_col_id;
    Gtk::TreeModelColumn<Glib::ustring> m_col_artist;
    Gtk::TreeModelColumn<Glib::ustring> m_col_album;
    Gtk::TreeModelColumn<Glib::ustring> m_col_title;
  };

  ModelColumns m_Columns;

  //Child widgets:
  Gtk::Box m_VBox;

  Gtk::ScrolledWindow m_ScrolledWindow;
  Gtk::TreeView m_TreeView;
  Glib::RefPtr<Gtk::ListStore> m_refTreeModel;


};

#endif
